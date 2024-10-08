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
    _this
        .title("")
        .xMax(xMax)
        .yMax(yMax)
        .onKey(Key::Up, &View::moveCursor, this)
        .onKey(Key::Down, &View::moveCursor, this)
        .onKey(Key::Left, &View::moveCursor, this)
        .onKey(Key::Right, &View::moveCursor, this);
    
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

    if(newX < 0) this->_x = 0;
    else if(newX > static_cast<int>(_xMax)) this->_x = _xMax;
    else this->_x = newX;

    if(newY < 0) this->_y = 0;
    else if(newY > static_cast<int>(_yMax)) this->_y = _yMax;
    else this->_y = newY;
}

void View::moveCursor(Key key){
    switch(key){
        case Key::Up:
            this->moveCursor(0, -1);
            break;
        case Key::Down:
            this->moveCursor(0, 1);
            break;
        case Key::Left:
            this->moveCursor(1, 0);
            break;
        case Key::Right:
            this->moveCursor(-1, 0);
            break;
        default:
            break;
    }
}