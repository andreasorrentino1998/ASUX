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

#include "navigator.h"

using namespace ASUX;

Navigator::Navigator(IViewFactory* viewFactory){
    this->viewFactory = viewFactory;
    this->navigationBarVisibility = true;
}

NavigationBar& Navigator::getNavigationBar(){
    return this->navigationBar;
}

void Navigator::setNavigationBarVisibility(const bool value){
    this->navigationBarVisibility = value;
}

bool Navigator::navigationBarShouldBeRendered() const {
    return this->navigationBarVisibility;
}

void Navigator::navigateTo(string viewID){
    if(find(viewIDStack.begin(), viewIDStack.end(), viewID) != viewIDStack.end()) return;

    // Create the view
    View* view = viewFactory->createView(viewID);

    // Update the navigation bar info
    this->navigationBar.setTitle(view->getTitle());
    if(viewStack.size() > 1){
        navigationBar.setBackLabel(viewStack.top()->getTitle());
        navigationBar.setBackButtonVisibility(true);
    }

    // Push the new view on the stack
    view->setNavigator(this);
    this->viewStack.push(view);
    this->viewIDStack.push_back(viewID);
}

View* Navigator::getCurrentView() {
    return this->viewStack.top();
}

void Navigator::navigateBack(){
    // Pop the last view on the stack
    if(this->viewStack.size() > 1){
        delete this->viewStack.top();     // Deallocate the view
        this->viewStack.pop();            // Remove the pointer on the stack with a pop
        this->viewIDStack.pop_back();     // Remove the last viewID from the stack
    }

    // Update the navigation bar info
    this->navigationBar.setTitle(viewStack.top()->getTitle());
    if(this->viewStack.size() == 1){
        navigationBar.setBackLabel("");
        navigationBar.setBackButtonVisibility(false);
    }
    else{
        // Get the back view (in order to update the back label)
        View *topView = this->viewStack.top();
        this->viewStack.pop();
        View *backView = this->viewStack.top();
        this->viewStack.push(topView);

        navigationBar.setBackLabel(backView->getTitle());
    }
}