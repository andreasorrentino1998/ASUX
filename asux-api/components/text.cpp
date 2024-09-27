/**
* ASUX: a mini C++ framework for creating interactive 
* user interfaces for terminal-based applications.
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

#include "text.h"

#include "../utility/string_util.h"
#include <iostream>

using namespace ASUX;

Text::Text(const string& text, Position position): UIComponent(position){
    this->_text = text;
    this->_color = Color::Default;
    this->_backgroundColor = Color::Default;
    this->_textStyle = TextStyle::None;
}

const string& Text::getText() const {
    return this->_text;
}

Color Text::getColor() const {
    return this->_color;
}

Color Text::getBackgroundColor() const {
    return this->_backgroundColor;
}

TextStyle Text::getTextStyle() const {
    return this->_textStyle;
}

Text& Text::text(const string& text){
    this->_text = text;
    return *this;
}

Text& Text::color(Color color){
    this->_color = color;
    return *this;
}

Text& Text::backgroundColor(Color color){
    this->_backgroundColor = color;
    return *this;
}

Text& Text::textStyle(TextStyle style){
    this->_textStyle = style;
    return *this;
}

void Text::render() const {
    // Set text color and background color
    cout << toANSICode(_color, _backgroundColor);

    string paddingLine = repeater(" ", _padding.left + _text.length()-1 + _padding.right) + "\n";
    string textLine = repeater(" ", _padding.left) + _text + repeater(" ", _padding.right) + "\n";
    
    // Render
    cout << repeater(paddingLine, _padding.top);
    cout << textLine;
    cout << repeater(paddingLine, _padding.bottom);

    // Reset color to default
    cout << RESET_BG_COLOR << flush;
}

const vector<UIComponent*> Text::build(){
    return {};
}