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

#include "option.h"

#include "../utility/string_util.h"
#include <iostream>
#include <iomanip>      // Provides: setw()

Option::Option(const string &title, const string &value, Position position): RawComponent(position){
    this->_title = title;
    this->_value = value;
}

Option::~Option(){

}

Option::Option(const char *title, const char *value){
    this->_title = title;
    this->_value = value;
}

Option& Option::title(const string &title){
    this->_title = title;
    return *this;
}

Option& Option::value(const string &value){
    this->_value = value;
    return *this;
}

const string* Option::render() const {
    //cout << toANSICode(_color) << left << setw(40) << _title << left << setw(35) << "◄ " + _value + " ►" << setw(0) << toANSICode(Color::Default);
    string rightSpace = "";
    string truncatedTitle  =_title.substr(0, 40);
    if(_title.length() < 40){
        rightSpace = repeater(" ", 40 - _title.length());
    }

    return new string(toANSICode(_color) + truncatedTitle + rightSpace + "◄ " + _value + " ►" + toANSICode(Color::Default));
}