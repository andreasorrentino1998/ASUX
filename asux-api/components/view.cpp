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

#include "view.h"

using namespace ASUX;

View::View(unsigned x, unsigned y, unsigned xMax, unsigned yMax): UIComponent(Position::Default){
    this->_title = "";
    this->_xMax = xMax;
    this->_yMax = yMax;

    if(this->_x < xMax) this->_x = x;
    else this->_x = xMax;

    if(this->_y < yMax) this->_y = y;
    else this->_y = yMax;
}

const string& View::getTitle() const {
    return _title;
};

int View::getX() const {
    return _x;
}

int View::getY() const {
    return _y;
}

int View::getMaxX() const {
    return _xMax;
}

int View::getMaxY() const {
    return _yMax;
}


void View::setTitle(string &title){
    this->_title = title;
};

void View::setNavigator(Navigator *navigator){
    this->navigator = navigator;
}

View& View::title(const string &title){
    this->_title = title;
    return *this;
}

View& View::x(unsigned value){
    this->_x = value;
    return *this;
}
View& View::y(unsigned value){
    this->_y = value;
    return *this;
}

View& View::xMax(unsigned value){
    this->_xMax = value;
    return *this;
}

View& View::yMax(unsigned value){
    this->_yMax = value;
    return *this;
}

void View::moveCursor(int x, int y){
    int newX = this->_x + x;
    int newY = this->_y + y;

    if(newX < _xMax) this->_x = newX;
    else if(newX < 0) this->_x = 0;
    else this->_x = _xMax;

    if(newY < _yMax) this->_y = newY;
    else if(newY < 0) this->_y = 0;
    else this->_y = _yMax;
}

void View::render() const {
    
}