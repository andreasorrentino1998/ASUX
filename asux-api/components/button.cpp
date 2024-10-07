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

Button::Button(const string& text, Position position): UIComponent(position){
    this->_padding = {0, 0, 0, 0 };
    this->_size = {5, 5};
    this->_text = text;
    this->_color = Color::Default;
}

Color Button::getColor() const {
    return this->_color;
}

Button& Button::color(Color color){
    this->_color = color;
    return *this;
}

Button& Button::text(const string& text){
    this->_text = text;
    return *this;
}

void Button::render() const {
    // Set button color
    cout << toANSICode(_color);

    // Degenerate case --> [text]
    if(_padding.top == _padding.bottom == 0){
        cout << "[" + repeater(' ', _padding.left) + _text + repeater(' ', _padding.right) + "]";
        cout << toANSICode(Color::Default);
        return;
    }

    // Calculate string piecies
    unsigned width = _padding.left + _text.length() + _padding.right;
    string topBorder = "┌" + repeater("─", width) + "┐\n";
    string paddingLine = "│" + repeater(' ', width) + "│\n";
    string textLine = "│" + repeater(' ', _padding.left) + _text + repeater(' ', _padding.right) + "│\n";
    string bottomBorder = "└" + repeater("─", width) + "┘";

    if(_padding.top > 0){
        cout << topBorder;
        cout << repeater(paddingLine, _padding.top - 1);
    }

    cout << textLine;

    if(_padding.bottom > 0){
        cout << repeater(paddingLine, _padding.bottom - 1);
        cout << bottomBorder;
    }

    // Reset color to default
    cout << RESET_BG_COLOR << flush;
}

const vector<UIComponent*> Button::build(){
    return {};
}