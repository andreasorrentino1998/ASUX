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

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "raw_component.h"
#include "properties/color.h"

namespace ASUX {

enum TextBoxType { PlainText, Password };

class TextBox: public RawComponent {
    private:
        string _title;
        string *_text;
        TextBoxType _type;
        bool _showTitle;
        Color _textColor;

        void handleKey(Key key);
    public:
        TextBox(unsigned width = 10, unsigned height = 1, Position position = Position::Default);
        TextBox& title(const string &value);
        TextBox& text(string *value);
        TextBox& type(TextBoxType type);
        TextBox& showTitle(bool value);
        TextBox& textColor(Color color);
        string getTitle() const;
        string getText() const;
        TextBoxType getType() const;
        bool shouldShowTitle() const;
        Color getTextColor() const;
        const string* render() const override;
};

}

#endif