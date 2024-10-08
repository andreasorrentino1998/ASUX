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
#include "input.h"
#include <cctype>       // Provides: toupper()

using namespace ASUX;
using namespace std;

App::App(){
    this->instance = nullptr;
    this->navigator = nullptr;
}

App* App::init(){
    App *app = new App();
    app->navigator = new Navigator();
    return app;
}

void App::setRootView(View *view){
    this->navigator->navigateTo(view);
}

void App::runLoop(){
    // Init the terminal
    Terminal::init();

    // Execute the first all cycle (in order to init the view model)
    // At the boot we suppose the model has been changed.
    bool modelChanged = true;

    do{
        // Get the current view controller, view and the navigation bar
        View *view = navigator->getCurrentView();
        NavigationBar navigationBar = this->navigator->getNavigationBar();

        // Render the updated UI if the model has changed
        // TODO: detect when the model changes in order to avoid redrawing the same content again.
        if(modelChanged){
            Terminal::clear();
            if(navigator->navigationBarShouldBeRendered()) Renderer::render(&navigationBar);
            Renderer::render(view);
            modelChanged = false;
        }

        // Get the keyboard input from user
        Key key = ASUX::Input::getInputKey();
        
        // App navigation logic
        switch(key){
            case Key::ESC:
                Terminal::deinit();
                exit(0);
                break;
            case Key::Backspace:
                Terminal::clear();
                navigator->navigateBack();
                break;
            default:
                Input::triggerActions(view, key);
                break;
        }
    
        // TODO: detect when the model changes
        modelChanged = true;
    } while(true);
}