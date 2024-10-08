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

#ifndef BUTTON_H
#define BUTTON_H

#include "raw_component.h"
#include "properties/color.h"
#include "properties/padding.h"

#include <string>

using namespace ASUX;
using namespace std;

namespace ASUX {

class Button: public RawComponent {
    private:
        string _text;
        Color _color;
    public:
        Button(const string& text = "Button", Position position = Position::Default);
        Color getColor() const;
        Button& color(Color color);
        Button& text(const string& text);
        const string* render() const override;
};

}

#endif