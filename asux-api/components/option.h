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

#ifndef OPTION_H
#define OPTION_H

#include "raw_component.h"
#include "properties/color.h"
#include <string>

using namespace ASUX;
using namespace std;

namespace ASUX {

class Option: public RawComponent {
    private:
        string _title;
        string _value;
        Color _color;
    public:
        Option(const string &title = "", const string &value = "", Position position = Position::Default);
        Option(const char *title, const char *value);
        ~Option();
        Color getColor() const;
        Option& color(Color color);
        Option& title(const string &title);
        Option& value(const string &value);
        const string* render() const override;
};

}

#endif