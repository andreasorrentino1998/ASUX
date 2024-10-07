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
#include "components/text.h"
#include "utility/string_util.h"

#include <iostream>     // Provides: cout
#include <vector>
#include <typeinfo>

using namespace ASUX;
using namespace std;

void Renderer::render(UIComponent *component){
    const vector<UIComponent*> children = component->build();
    if(children.size() == 0){
        cout << repeater("\n", component->getMarginTop());
        component->render();
        cout << repeater("\n", component->getMarginBottom());
        cout << (component->getPosition() == Position::Default ? "\n": "") << flush;
        return;
    }

    for(unsigned i = 0; i < children.size(); i++) render(children[i]);

    cout << (component->getPosition() == Position::Default ? "\n": "") << flush;
    /*if(View* ptr = dynamic_cast<View*>(component); ptr != nullptr){
        cout << "è di tipo View";
        
    }
    else delete component;*/

    // Free all children components
    for(UIComponent* child: children) delete child;

    /*if(component->structure().childrenCount == 0){
        cout << repeater("\n", component->getMarginTop());
        component->render();
        cout << repeater("\n", component->getMarginBottom());
    }

    for(unsigned i = 0; i < component->structure().childrenCount; i++)
        render(component->structure().children[i]);

    cout << (component->getPosition() == Position::Default ? "\n": "") << flush;*/
}

/*void Renderer::render(list<ControllerOption> *options){
    cout << toANSICode(Color::Cyan);
    for(ControllerOption option: *options){
        if(option.key == "\n") cout << "[↵] " << option.name << " | ";
        else cout << "[" << option.key << "] " << option.name << " | ";
    }
    cout << toANSICode(Color::Default) << std::flush;
}*/