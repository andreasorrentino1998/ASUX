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

#include "textbox.h"

#include "../utility/string_util.h"
#include <iostream>

using namespace ASUX;

TextBox::TextBox(unsigned width, unsigned height, Position position){
    this->_size.width = width;
    this->_size.height = height;
    this->_position = position;
    this->_color = Color::Default;
    this->_textColor = Color::Default;
    this->_type = TextBoxType::PlainText;
    this->_text = nullptr;

    this->onKey(Key::Any, &TextBox::handleKey, this);
}

TextBox& TextBox::title(const string &value){
    this->_title = value;
    return *this;
}

TextBox& TextBox::text(string *value){
    this->_text = value;
    return *this;
}

TextBox& TextBox::type(TextBoxType type){
    this->_type = type;
    return *this;
}

TextBox& TextBox::showTitle(bool value){
    this->_showTitle = value;
    return *this;
}

TextBox& TextBox::textColor(Color color){
    this->_textColor = color;
    return *this;
}

string TextBox::getTitle() const {
    return this->_title;
}

string TextBox::getText() const{
    return this->_text != nullptr ? *this->_text : "";
}

TextBoxType TextBox::getType() const {
    return this->_type;
}

bool TextBox::shouldShowTitle() const {
    return this->_showTitle;
}

Color TextBox::getTextColor() const {
    return this->_textColor;
}

void TextBox::handleKey(Key key){
    if(this->_text == nullptr) return;

    if(key == Key::Backspace && (*this->_text).length() > 0) (*this->_text).pop_back();
    if(key == Key::Space) (*this->_text) += " ";
    if(key == Key::Slash) (*this->_text) += (char) key;
    else if((key >= Key::A && key <= Key::Z) || (key >= Key::a && key <= Key::z) || (key >= Key::N0 && key <= Key::N9))
        (*this->_text) += (char) key;
}

const string* TextBox::render() const {
    string component = "";
    component += toANSICode(_color) + "╭─";
    
    if(this->_showTitle){
        string clippedTitle;
        if(this->_size.width < this->_title.length() + 3){
            clippedTitle = this->_title.substr(0, this->_size.width - 3);
            component += clippedTitle;
        }
        else{
            component += this->_title + repeater("─", this->_size.width - this->_title.length() - 3);
        } 
    }
    else component += repeater("─", this->_size.width - 3);
    
    component += "╮\n";

    // TODO: Implement height.

    string clippedText;
    size_t textLength = (*this->_text).length();
    if(this->_size.width < textLength + 2){
        size_t clippedTextStartOffset = textLength - (this->_size.width - 2);
        clippedText = (*this->_text).substr(clippedTextStartOffset, this->_size.width - 2);
        component += "│" + toANSICode(_textColor);
        this->_type == TextBoxType::Password? component += repeater("*", clippedText.length()): component += clippedText;
        component += toANSICode(_color) + "│\n";
    }
    else{
        size_t padding = (this->_size.width - 2 - textLength);
        component += "│" + toANSICode(_textColor);
        this->_type == TextBoxType::Password? component += repeater("*", textLength): component += (*this->_text);
        component += repeater(" ", padding) + toANSICode(_color) + "│\n";
    }
    component += "╰" + repeater("─", this->_size.width - 2) + "╯";
    
    return new string(component);
}