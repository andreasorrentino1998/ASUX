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

#include "button.h"

#include "../utility/string_util.h"
#include <iostream>

using namespace ASUX;

Button::Button(const string& text, Position position): RawComponent(position){
    this->_padding = {0, 0, 0, 0 };
    this->_size = {5, 5};
    this->_text = text;
    this->_color = Color::Default;
}

Button& Button::text(const string& text){
    this->_text = text;
    return *this;
}

const string* Button::render() const {
    string component = "";

    // Set button color
    component += toANSICode(_color);

    // Degenerate case --> [text]
    if(_padding.top == _padding.bottom == 0){
        component += "[" + repeater(' ', _padding.left) + _text + repeater(' ', _padding.right) + "]";
        component += toANSICode(Color::Default);
        return new string(component);
    }

    // Calculate string piecies
    unsigned width = _padding.left + _text.length() + _padding.right;
    string topBorder = "┌" + repeater("─", width) + "┐";
    string paddingLine = "│" + repeater(' ', width) + "│";
    string textLine = "│" + repeater(' ', _padding.left) + _text + repeater(' ', _padding.right) + "│";
    string bottomBorder = "└" + repeater("─", width) + "┘";

    if(_padding.top > 0){
        component += topBorder + "\n";
        component += repeater(paddingLine + "\n", _padding.top - 1);
    }

    component += textLine;

    if(_padding.bottom > 0){
        component += repeater("\n" + paddingLine, _padding.bottom - 1);
        component += "\n" + bottomBorder;
    }

    // Reset color to default
    component += RESET_BG_COLOR;

    return new string(component);
}