/**
* ASUX: A lightweight C++ reactive framework for building terminal-based applications.
* 
* Authors:
* © 2024 - Andrea Sorrentino
* 
* ASUX is free software: you can redistribute it and/or modify it under the
* terms of the GNU General Public License as published by the Free Software Foundation,
* either version 3 of the License, or (at your option) any later version.
*  
* ASUX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License along with ASUX.
* If not, see <http://www.gnu.org/licenses/>.
*/

#include "app.h"

#include "renderer.h"
#include "terminal.h"
#include "builder.h"
#include "input.h"
#include "components/textbox.h"

#include <chrono>
#include <thread>
#include <cctype>       // Provides: toupper()

using namespace ASUX;
using namespace std;

App::App(){
    this->instance = nullptr;
    this->navigator = nullptr;
}

App* App::init(IViewFactory *viewFactory){
    App *app = new App();
    app->navigator = new Navigator(viewFactory);
    return app;
}

void App::setRootView(string viewID){
    this->navigator->navigateTo(viewID);
}

void App::registerRunnable(Runnable& runnable){
    tasks.emplace_back(PeriodicTask{
        .refreshTime = runnable.getRefreshRate(),
        .lastUpdate = chrono::high_resolution_clock::now(),
        .runnable = &runnable,
    });
}

void App::refresh(UIComponent *component){
    // Rebuild the component
    Builder::build(component);

    // Get the current view and the navigation bar
    View *view = navigator->getCurrentView();
    NavigationBar& navigationBar = this->navigator->getNavigationBar();

    // Render the entire view again
    Terminal::clear();
    if(navigator->navigationBarShouldBeRendered()) Renderer::render(&navigationBar);
    Renderer::render(view);
}

void App::eventLoop(){
    while(!shouldExit){
        Key key = Input::getInputKey();
        {
            lock_guard<mutex> lock(queueMutex);
            keyEventsQueue.push_back(key);
        }
    }
}

void App::runLoop(){
    // Init the terminal
    Terminal::init();

    View *oldView = nullptr;

    // Add a task for updating the view
    tasks.emplace_back(PeriodicTask{
        .callback = [&](){ this->refresh(this->navigator->getCurrentView()); },
        .refreshTime = 1.0 / 10,
        .lastUpdate = chrono::high_resolution_clock::now(),
        .runnable = nullptr,
    });

    // Start the event loop
    thread eventLoopThread(&App::eventLoop, this);
    
    while(true){
        // Execute the periodic tasks
        for(auto& task: tasks){
            chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - task.lastUpdate;
            if(elapsed.count() >= task.refreshTime){
                task.lastUpdate = chrono::high_resolution_clock::now();
                if(task.runnable != nullptr){
                    task.refreshTime = task.runnable->getRefreshRate();
                    task.runnable->onUpdate();
                }
                else task.callback();
            }
        }

        // Calculate the nextFrameTime for the earliest periodic task
        /*auto earliest = min_element(tasks.begin(), tasks.end(), [](auto& t1, auto& t2) {
            return t1.lastUpdate + chrono::duration<double>(t1.refreshTime) < t2.lastUpdate + chrono::duration<double>(t2.refreshTime);
        });
        auto nextFrameTime = earliest->lastUpdate + chrono::duration<double>(earliest->refreshTime);*/

        // Get the current view and the navigation bar
        View *view = navigator->getCurrentView();
        NavigationBar& navigationBar = this->navigator->getNavigationBar();

        // If there is a different view on the screen
        // We need to build it, so the view is marked as dirty component.
        if(view != oldView){
            view->setDirty(true);
            oldView = view;
        }

        // Process the user input
        queueMutex.lock();
        if(keyEventsQueue.size() > 0){
            Key key = keyEventsQueue.front();
            keyEventsQueue.pop_front();
            queueMutex.unlock();

            // App navigation logic
            switch(key){
                case Key::ESC:
                    shouldExit = true;
                    if(eventLoopThread.joinable()) eventLoopThread.join();
                    Terminal::deinit();
                    exit(0);
                    break;
                case Key::Backspace:
                    // If the focused component is a TextBox, don't navigate back
                    Input::triggerActions(view, key);
                    if(!(dynamic_cast<TextBox*>(view->getFocusedComponent()))) navigator->navigateBack();
                    break;
                default:
                    Input::triggerActions(view, key);
                    break;
            }
        }
        queueMutex.unlock();

        // Sleep for synchronizing to the target FPS
        //this_thread::sleep_until(nextFrameTime);
        this_thread::sleep_for(chrono::duration<double>(0.0001));
    }
}