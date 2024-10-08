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

#ifndef NAVIGATION_BAR_H
#define NAVIGATION_BAR_H

#include "raw_component.h"
#include "properties/color.h"
#include <string>

// ANSI TEXT FORMATTING ESCAPE SEQUENCES
#define BOLD_TEXT "\033[1m"
#define NORMAL_TEXT "\033[22m"
#define RESET_TEXT "\033[0m"

using namespace ASUX;
using namespace std;

namespace ASUX {

class NavigationBar: public RawComponent {
    private:
        string title;
        string backLabel;
        bool backButtonVisibility;
    public:
        NavigationBar();
        const string& getTitle() const;
        const string& getBackLabel() const;
        void setTitle(const string &title);
        void setBackLabel(const string &title);
        void setBackButtonVisibility(const bool value);
        const string* render() const override;
};

}

#endif