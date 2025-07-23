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

#include "builder.h"
#include "components/view.h"
#include "components/raw_component.h"

using namespace ASUX;

void Builder::build(UIComponent *component){
    // If it's a raw component, it doesn't have child, so just return.
    // Otherwise deallocate its old children and build them again.
    if(RawComponent *raw = dynamic_cast<RawComponent*>(component)) return;

    // If it's dirty, rebuild it. But first, deallocate its children.
    if(component->isDirty()){
        vector<UIComponent*> children = component->getChildren();
        if(children.size() > 0){
            for(UIComponent* child: children) delete child;
        }

        // Build its children recursively.
        // We set them as dirty, so we can rebuild them using recursion.
        component->setChildren(component->build());
        children = component->getChildren();
        for(unsigned i = 0; i < children.size(); i++) build(children[i]);

        component->setDirty(false);
    }
    
    // If it's a view (root component) get the new focused component
    // And set its focus property to true.
    if(View *view = dynamic_cast<View*>(component)){
        int focusableElements = view->getNumberOfFocusableComponents();
        view->yMax(focusableElements - 1);
        
        UIComponent *focusedComponent = view->getFocusedComponent();
        if(focusedComponent != nullptr){
            focusedComponent->focus(true);
            focusedComponent->color(view->getFocusColor());
        }
    }
}