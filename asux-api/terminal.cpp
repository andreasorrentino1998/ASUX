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

#include "terminal.h"

#include <sys/ioctl.h>      // Provides: winsize, ioctl()
#include <unistd.h>         // Provides: STDOUT_FILENO
#include <csignal>          // Provides: signal()
#include <stdlib.h>         // Provides: exit()
#include <iostream>         // Provides: cout

using namespace ASUX;
using namespace std;

struct termios orig_termios;

void Terminal::init(){
    cout << "\033[?25l" << flush;   // Hide cursor
    clear();
}

void Terminal::deinit(){
    cout << "\033[?25h";    // Show cursor
}

Size getWindowSize(){
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    Size size = {win.ws_row, win.ws_col};
    return size;
}

void Terminal::setRawMode(termios& orig_termios){
    termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void Terminal::resetMode(termios& orig_termios){
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void Terminal::clear(){
    system("clear && printf '\\e[3J'");
}

// Reset the terminal mode when the a signal is raised
void signalHander(int signal){
    Terminal::resetMode(orig_termios);
    Terminal::deinit();
    exit(signal);
}

char* Terminal::getChar(const size_t n){
    // Buffer to store ASCII char sequence
    char *buffer = new char[n]{0};
    
    // Signal handler
    signal(SIGINT, signalHander);

    // Get the current terminal configuration
    tcgetattr(STDIN_FILENO, &orig_termios);

    // Set the terminal in raw mode
    setRawMode(orig_termios);

    // Read the last N characters
    read(STDIN_FILENO, buffer, n);

    // Reset the terminal mode
    resetMode(orig_termios);

    return buffer;
}