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
#include <cctype>       // Provides: toupper()

using namespace ASUX;
using namespace std;

App::App(){
    this->instance = nullptr;
    this->navigationController = nullptr;
}

App* App::init(){
    App *app = new App();
    app->navigationController = new NavigationController();
    app->navigator = new Navigator();
    return app;
}

void App::setRootViewController(ViewController *viewController){
    this->navigationController->navigateTo(viewController);
}

void App::setRootView(View *view){
    this->navigator->navigateTo(view);
}

void executeActions(UIComponent *component, Key key){
    const vector<UIComponent*> children = component->build();
    for(unsigned i = 0; i < children.size(); i++) executeActions(children[i], key);
    
    if(component->actions.find(key) != component->actions.end()){
        component->actions[key]->call(key);
    }
}

void App::runLoop(){
    // Init the terminal
    Terminal::init();

    // Execute the first all cycle (in order to init the view model)
    // At the boot we suppose the model has been changed.
    //this->navigationController->currentViewController()->run(' ');
    bool modelChanged = true;

    do{
        // Get the current view controller, view and the navigation bar
        /*ViewController *viewController = navigationController->currentViewController();
        View *view = viewController->getView();
        NavigationBar navigationBar = this->navigationController->getNavigationBar();*/
        View *view = navigator->getCurrentView();
        NavigationBar navigationBar = this->navigator->getNavigationBar();

        // Render the updated UI if the model is changed
        // TODO: implement a mechanism to detect when the model is changed
        // in order to avoid redrawing the same content again.
        //if(navigationController->navigationBarShouldBeRendered())
        if(modelChanged){
            Terminal::clear();
            if(navigator->navigationBarShouldBeRendered()) Renderer::render(&navigationBar);
            Renderer::render(view);
            modelChanged = false;
        }
        //Renderer::render(viewController->setOptions());

        // Get inputs from user (blocking)
        char command = Terminal::getKey();

        /* If the view controller has the "writing mode" enabled (e.g. the user is typing on a search bar),
        the main app should not intercept the inputs until the view controller hasn't disabled that mode. */
        /*if(viewController->hasWritingModeEnabled()){
            viewController->run(command);
            Terminal::clear();
            continue;
        }*/

        // App navigation logic
        switch(toupper(command)){
            case 'X':
                Terminal::deinit();
                exit(0);
                break;
            case 127: // Backspace
                Terminal::clear();
                //navigationController->navigateBack();
                navigator->navigateBack();
                break;
            case 27: // ESC
                command = Terminal::getKey();
                if(command == '['){
                    command = Terminal::getKey();
                    switch(std::toupper(command)){
                        case 'A':    // UP Arrow -> "ESC [ A"
                            view->moveCursor(0, -1);
                            executeActions(view, Key::Up);
                            break;
                        case 'B':   // DOWN Arrow -> "ESC [ B"
                            view->moveCursor(0, 1);
                            executeActions(view, Key::Down);
                            break;
                        case 'C':   // RIGHT Arrow -> "ESC [ C"
                            view->moveCursor(1, 0);
                            executeActions(view, Key::Right);
                            break;
                        case 'D':   // LEFT Arrow -> "ESC [ D"
                            view->moveCursor(-1, 0);
                            executeActions(view, Key::Left);
                            break;
                    }
                }
                // TODO: detect when the model changes
                modelChanged = true;
                break;
            default:
                break;
        }
    
    } while(true);
}