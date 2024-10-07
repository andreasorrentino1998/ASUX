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

namespace ASUX {

enum class ListStyle {
    None,
    Enumerated,
    Bullet,
    Arrow,
};

typedef function<UIComponent*(unsigned index)> ListBuilder;

class UIList: public UIComponent {
    protected:
        //vector<UIComponent*> *_items;       // Vector of pointers, otherwise you will lose the specialization (object slicing)
        unsigned _itemsCount;
        ListBuilder _builder;
        ListStyle _style;
        unsigned _spacing;
    public:
        //map<Key, function<void(unsigned)>> itemsActions;
        UIList();
        void style(ListStyle style);
        void spacing(unsigned value);
        void render() const override;
        UIList& itemsCount(unsigned value);
        UIList& builder(ListBuilder _builder);
        const vector<UIComponent*> build() override;
        //UIList& onKey(Key key, function<void(unsigned)> callback);
};

}

#endif