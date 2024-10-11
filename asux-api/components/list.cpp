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

List::List(){
    this->_itemsCount = 0;
    this->_style = ListStyle::Arrow;
    this->_spacing = 0;
    this->itemBuilder = nullptr;
}

void List::style(ListStyle style){
    this->_style = style;
}

void List::spacing(unsigned value){
    this->_spacing = value;
}

List& List::itemsCount(unsigned value){
    this->_itemsCount = value;
    return *this;
}

List& List::builder(ListBuilder itemBuilder){
    this->itemBuilder = itemBuilder;
    return *this;
}

const vector<UIComponent*> List::build(){
    vector<UIComponent*> items;
    for(unsigned i = 0; i < _itemsCount; i++){
        const vector<UIComponent*> itemChildren = this->itemBuilder(i);
        size_t childrenCount = itemChildren.size();
        for(unsigned j = 0; j < childrenCount; j++) items.push_back(itemChildren[j]);
    }
    return items;
}