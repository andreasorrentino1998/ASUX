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

#ifndef ACTION_H
#define ACTION_H

#include "components/component.h"
#include "key.h"

namespace ASUX {

// Forward declaration
class UIComponent;

class Action {
    public:
        virtual ~Action() = default;
        virtual UIComponent* getInstance() = 0;
        virtual void operator()(Key key) = 0;
};

template <typename T>
class ComponentAction: public Action {
    private:
        using FuncT = void (T::*)(Key key);
        T* instance;
        FuncT func;
    public:
        ComponentAction(T* instance, FuncT func){
            this->instance = instance;
            this->func = func;
        }

        UIComponent* getInstance(){ return static_cast<UIComponent*>(this->instance); }
        void operator()(Key key){ (instance->*func)(key); }
};

}

#endif