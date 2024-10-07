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

#include "color.h"

using namespace ASUX;

namespace ASUX{

Color& operator+=(Color& color, int value){
    if(value > 0){
        int id = color + value;
        if(id == 8) return color = Color::Default;
        else if(id > Color::Default) return color = Color::Black;
        else return color = (Color) id;
    }
    if(value < 0){
        int id = color + value;
        if(id == 8) return color = Color::White;
        else if(id < Color::Black) return color = Color::Default;
        else return color = (Color) id;
    } 
    else return color;
}

Color& operator-=(Color& color, int value){
    return color += -value;
}

string toString(Color color){
    string colorStrings[10] = {
        "Black",
        "Red",
        "Green",
        "Yellow",
        "Blue",
        "Magenta",
        "Cyan",
        "White",
        "",
        "Default"
    };
    return colorStrings[color];
}

}