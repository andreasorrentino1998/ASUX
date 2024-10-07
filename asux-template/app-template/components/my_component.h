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

#ifndef MY_COMPONENT_H
#define MY_COMPONENT_H

#include "ASUX/components/components.h"

using namespace ASUX;

class MyComponent: public UIComponent {
    public:
        const vector<UIComponent*> build() override {
            return {
                _(Text)
                    .text("This is my custom component with a text and a button."),
                _(Button)
                    .text("My Button")
            };
        }
};

#endif