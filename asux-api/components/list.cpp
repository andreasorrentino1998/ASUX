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
    this->y = 0;
    this->_itemsCount = 0;
    this->_itemsToDisplay = 0;
    this->_scrollable = false;
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

List& List::startIndex(unsigned index){
    if(this->y < this->_itemsCount) this->y = index;
    else this->y = this->_itemsCount - 1;
    return *this;
}

List& List::scrollable(bool value){
    this->_scrollable = value;
    return *this;
}
List& List::itemsToDisplay(unsigned number){
    this->_itemsToDisplay = number;
    return *this;
}

List& List::builder(ListBuilder itemBuilder){
    this->itemBuilder = itemBuilder;
    return *this;
}

int List::getNumberOfFocusableComponents() const {
    return this->_itemsCount;
}

UIComponent* List::getFocusableElementByIndex(int index) const {
    if(_scrollable){
        if(index < (int) _itemsCount){
            if(this->y < _itemsToDisplay / 2.0) return this->children[index];
            else if(this->y + (_itemsToDisplay / 2.0) < _itemsCount) return this->children[(_itemsToDisplay / 2)];
            else return this->children[(_itemsToDisplay - 1) - ((_itemsCount-1) - this->y)];
        }
        else return nullptr;
    }

    int i = -1;

    for(UIComponent* child: this->children){
        if(child->isFocusable()) i++;
        if(i == index) return child;

        // Check if it has focusable child too
        UIComponent *component = child->getFocusableElementByIndex(index - (i + 1));
        if(component != nullptr) return component;
        else {
            i += child->getNumberOfFocusableComponents();
        }
    }

    return nullptr;
}

// Build the item with the specified index and add it to the passed list.
void List::buildItemAndAddToList(unsigned index, vector<UIComponent*> &itemsList){
    const vector<UIComponent*> itemChildren = this->itemBuilder(index);
    size_t childrenCount = itemChildren.size();
    for(unsigned j = 0; j < childrenCount; j++) itemsList.push_back(itemChildren[j]);
}

const vector<UIComponent*> List::build(){
    /* This condition implement a fixed N items scrollable list.
    The item is shown if it meets at least one of these 3 conditions:
        1. The item is inside the interval [y-(N/2), y+(N/2)], where y is the position of the list cursor.
        2. The item is inside the initial interval [0,N] and the cursor position is not beyond the half of this interval.
        3. The item is one of the last N of the list, and the cursor position + (N/2) exceed the list length.
    */
    #define condition1(i) ((int)i >= (int)(this->y - middleY) && i <= this->y + middleY)
    #define condition2(i) (i >= 0 && i < _itemsToDisplay && this->y < middleY)
    #define condition3(i) (this->y + middleY >= _itemsCount && (int)i >= (int)(_itemsCount - _itemsToDisplay))
    
    unsigned middleY = _itemsToDisplay / 2;
    vector<UIComponent*> items;
    for(unsigned i = 0; i < _itemsCount; i++){
        if(_scrollable){
            if(condition1(i) || condition2(i) || condition3(i))
                buildItemAndAddToList(i, items);
        }
        else buildItemAndAddToList(i, items);
    }
    return items;
}