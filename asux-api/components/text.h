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

#ifndef TEXT_H
#define TEXT_H

#include "raw_component.h"
#include "properties/color.h"
#include "properties/padding.h"

#include <string>

using namespace ASUX;
using namespace std;

namespace ASUX {

enum class TextStyle { None, Capitalized, Lowercase, Uppercase };

class Text: public RawComponent {
    private:
        string _text;
        Color _backgroundColor;
        TextStyle _textStyle;
    public:
        Text(const string& text = "", Position position = Position::Default);
        const string& getText() const;
        Color getBackgroundColor() const;
        TextStyle getTextStyle() const;
        Text& text(const string& text);
        Text& backgroundColor(Color color);
        Text& textStyle(TextStyle style);
        const string* render() const override;
};

}

#endif