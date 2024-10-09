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
#include "components/raw_component.h"

using namespace ASUX;

void Builder::build(UIComponent *component){
    // If it's a raw component, it doesn't have child, so just return.
    // Otherwise deallocate its old children and build them again.
    if(RawComponent *raw = dynamic_cast<RawComponent*>(component)) return;
    
    if(component->children.size() > 0){
        for(UIComponent* child: component->children) delete child;
    }
    
    // Build its children recursively
    component->children = component->build();
    for(unsigned i = 0; i < component->children.size(); i++) build(component->children[i]);
}