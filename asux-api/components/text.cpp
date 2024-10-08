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

#include "text.h"

#include "../utility/string_util.h"
#include <iostream>

using namespace ASUX;

Text::Text(const string& text, Position position): RawComponent(position){
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

const string* Text::render() const {
    string component = "";

    // Set text color and background color
    component += toANSICode(_color, _backgroundColor);

    string paddingLine = repeater(" ", _padding.left + _text.length() + _padding.right) + "\n";
    string textLine = repeater(" ", _padding.left) + _text + repeater(" ", _padding.right) + "\n";
    
    // Render
    component += repeater(paddingLine, _padding.top);
    component += textLine;
    component += repeater(paddingLine, _padding.bottom);

    // Reset color to default
    component += RESET_BG_COLOR;

    return new string(component);
}