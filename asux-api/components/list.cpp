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

#include "list.h"

using namespace ASUX;

UIList::UIList(){
    this->_itemsCount = 0;
    this->_style = ListStyle::Arrow;
    this->_spacing = 0;
    this->_builder = nullptr;
}

void UIList::style(ListStyle style){
    this->_style = style;
}

void UIList::spacing(unsigned value){
    this->_spacing = value;
}

UIList& UIList::itemsCount(unsigned value){
    this->_itemsCount = value;
    return *this;
}

UIList& UIList::builder(ListBuilder _builder){
    this->_builder = _builder;
    return *this;
}

const vector<UIComponent*> UIList::build(){
    vector<UIComponent*> items;
    for(unsigned i = 0; i < _itemsCount; i++){
        items.push_back(_builder(i));
    }
    return items;
}