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

#ifndef COLOR_H
#define COLOR_H

#include <string>

using namespace std;

namespace ASUX {

    // ANSI FOREGROUND COLORS ID (8-16 bit)
    #define BLACK_COLOR "\033[30m"
    #define RED_COLOR "\033[31m"
    #define GREEN_COLOR "\033[32m"
    #define YELLOW_COLOR "\033[33m"
    #define BLUE_COLOR "\033[34m"
    #define MAGENTA_COLOR "\033[35m"
    #define CYAN_COLOR "\033[36m"
    #define WHITE_COLOR "\033[37m"
    #define DEFAULT_COLOR "\033[39m"
    
    #define RESET_BG_COLOR "\033[0m"

    enum Color {
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
        Default = 9
    };

    Color& operator+=(Color& color, int value);
    Color& operator-=(Color& color, int value);

    inline string toANSICode(Color color){
        return "\033[" + to_string(30 + color) + "m";
    }

    inline string toANSICode(Color color, Color bgColor){
        return "\033[" + to_string(30 + color) + ";" + to_string(40 + bgColor) + "m";
    }

    string toString(Color color);

}

#endif