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

void App::runLoop(){
    // Init the terminal
    Terminal::init();

    View *oldView = nullptr;
    
    do{
        // Get the current view and the navigation bar
        View *view = navigator->getCurrentView();
        NavigationBar& navigationBar = this->navigator->getNavigationBar();

        // If there is a different view on the screen
        // We need to build it, so the view is marked as dirty component.
        if(view != oldView){
            view->setDirty(true);
            oldView = view;
        }
        
        // Refresh the view
        refresh(view);

        // Get the keyboard input from user
        Key key = Input::getInputKey();
        
        // App navigation logic
        switch(key){
            case Key::ESC:
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
    } while(true);
}