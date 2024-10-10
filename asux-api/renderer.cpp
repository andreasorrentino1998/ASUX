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

#include "renderer.h"

#include "components/component.h"
#include "components/view.h"
#include "components/text.h"
#include "utility/string_util.h"

#include <iostream>     // Provides: cout
#include <vector>
#include <typeinfo>

using namespace ASUX;
using namespace std;

void Renderer::render(UIComponent *component){
    // If the component is set as invisible, don't render it.
    if(!component->getVisibility()) return;

    // If the component is focused, render the focus color and the cursor eventually 
    if(component->isFocused()){
        cout << toANSICode(component->getColor());
        cout << (component->shouldShowCursor()? "➤ ": "");
    }

    // Render the parent component
    const vector<UIComponent*> children = component->getChildren();
    if(children.size() > 0){
        cout << repeater("\n", component->getMarginTop());

        // Render its children
        for(unsigned i = 0; i < children.size(); i++) render(children[i]);

        cout << repeater("\n", component->getMarginBottom()) << flush;
    }
    // Render the leaf component
    else{
        cout << repeater("\n", component->getMarginTop());

        if(RawComponent *raw = dynamic_cast<RawComponent*>(component)){
            cout << *raw->render() << flush;
        }

        cout << repeater("\n", component->getMarginBottom());
        cout << (component->getPosition() == Position::Default ? "\n": "") << flush;
        return;
    }
}