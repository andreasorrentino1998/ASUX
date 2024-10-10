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

#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include "ASUX/components/components.h"
#include "../components/my_component.h"

using namespace ASUX;

class MainView: public View {
    public:
        MainView(){
            _this
                .title("MAIN VIEW");
        }

        const vector<UIComponent*> build() override {
            return {
                _(Text)
                    .text("Hello World"),
                _(MyComponent)
            };
        }
};

#endif