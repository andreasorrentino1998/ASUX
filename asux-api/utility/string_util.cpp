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

#include "string_util.h"

string repeater(const char c, const unsigned n){
    string str = "";
    for(unsigned i = 0; i < n; i++) str += c;
    return str;
}

string repeater(const string& s, const unsigned n){
    string str = "";
    for(unsigned i = 0; i < n; i++) str += s;
    return str;
}