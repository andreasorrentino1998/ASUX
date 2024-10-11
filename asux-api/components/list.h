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

#ifndef UI_LIST_H
#define UI_LIST_H

#include "component.h"

#include <functional>
#include <vector>

// Macro to simply declarative syntax
#define _builder(...) \
    .builder([&](unsigned i) -> const std::vector<UIComponent*> \
        { return { __VA_ARGS__ }; } \
    )

namespace ASUX {

enum class ListStyle {
    None,
    Enumerated,
    Bullet,
    Arrow,
};

typedef function<const vector<UIComponent*>(unsigned index)> ListBuilder;

class List: public UIComponent {
    protected:
        unsigned y;
        unsigned _itemsCount;
        unsigned _itemsToDisplay;
        bool _scrollable;
        ListBuilder itemBuilder;
        ListStyle _style;
        unsigned _spacing;
        void buildItemAndAddToList(unsigned index, vector<UIComponent*> &itemsList);
    public:
        List();
        void style(ListStyle style);
        void spacing(unsigned value);
        List& scrollable(bool value);
        List& itemsCount(unsigned number);
        List& itemsToDisplay(unsigned number);
        List& startIndex(unsigned index);
        List& builder(ListBuilder itemBuilder);
        const vector<UIComponent*> build() override;

        int getNumberOfFocusableComponents() const override;
        UIComponent* getFocusableElementByIndex(int index) const override;
};

}

#endif