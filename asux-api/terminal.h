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

#ifndef TERMINAL_H
#define TERMINAL_H

#include "components/properties/size.h"

#include <termios.h>        // Provides: termios

using namespace ASUX;

namespace ASUX {

namespace Terminal {
    // NOTE: IT WORKS ONLY FOR UNIX-based SYSTEMS
    // TODO: Add Windows support!
    void init();
    void deinit();
    Size getWindowSize();
    void setRawMode(termios& orig_termios);
    void resetMode(termios& orig_termios);
    char getKey();
    void clear();
};

}

#endif