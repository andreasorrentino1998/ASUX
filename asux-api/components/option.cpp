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

#include "option.h"

#include <iostream>
#include <iomanip>      // Provides: setw()

Option::Option(const string &title, const string &value, Position position): UIComponent(position){
    this->_title = title;
    this->_value = value;
}

Option::~Option(){

}

Option::Option(const char *title, const char *value){
    this->_title = title;
    this->_value = value;
}

Color Option::getColor() const {
    return this->_color;
}

Option& Option::color(Color color){
    this->_color = color;
    return *this;
}

Option& Option::title(const string &title){
    this->_title = title;
    return *this;
}

Option& Option::value(const string &value){
    this->_value = value;
    return *this;
}

void Option::render() const {
    cout << toANSICode(_color) << left << setw(40) << _title << left << setw(35) << "◄ " + _value + " ►" << setw(0) << toANSICode(Color::Default);
}

const vector<UIComponent*> Option::build(){
    return {};
}