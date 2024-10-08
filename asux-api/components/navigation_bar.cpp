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

#include "navigation_bar.h"

#include <iostream>

using namespace ASUX;
using namespace std;

NavigationBar::NavigationBar(): RawComponent(Position::Default){
    title = backLabel = "";
    backButtonVisibility = false;
}

const string& NavigationBar::getTitle() const {
    return title;
}

const string& NavigationBar::getBackLabel() const {
    return backLabel;
}

void NavigationBar::setTitle(const string &title){
    this->title = title;
}

void NavigationBar::setBackLabel(const string &title){
    backLabel = title;
}

void NavigationBar::setBackButtonVisibility(const bool value){
    backButtonVisibility = value;
}

const string* NavigationBar::render() const {
    string component = "";
    if(backButtonVisibility) component += "< " + backLabel + "\t";  // BOLD: ━━━━━━
    component += toANSICode(Color::Cyan) + BOLD_TEXT + "─────────── " + title + " ────────────────" + NORMAL_TEXT + toANSICode(Color::Default);
    return new string(component);
}