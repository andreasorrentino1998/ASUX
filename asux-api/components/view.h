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

#ifndef VIEW_H
#define VIEW_H

#include "component.h"
#include "../navigator.h"
#include <string>

using namespace std;

namespace ASUX {

// Forward declaration
class Navigator;

class View: public UIComponent {
    protected:
        string _title;
        Navigator *navigator;
        unsigned _x;
        unsigned _y;
        unsigned _xMax;
        unsigned _yMax;
        Color _focusColor;
    public:
        View(unsigned x = 0, unsigned y = 0, unsigned xMax = 0, unsigned yMax = 0);
        virtual ~View(){}
        
        const string& getTitle() const;
        int getX() const;
        int getY() const;
        int getMaxX() const;
        int getMaxY() const;
        
        UIComponent* getFocusedComponent() const override;
        Color getFocusColor() const;

        void moveCursor(int x, int y);
        void moveCursor(Key key);

        void setTitle(string &title);
        void setNavigator(Navigator *navigator);

        View& title(const string &title);
        View& x(unsigned value);
        View& y(unsigned value);
        View& xMax(unsigned value);
        View& yMax(unsigned value);
        View& focusColor(Color color);
};

}

#endif