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

#include "key.h"

namespace ASUX {

class Action {
    public:
        virtual ~Action() = default;
        virtual void operator()(Key key) = 0;
};

template <typename T>
class MemberAction : public Action {
    public:
        using FuncT = void (T::*)(Key key);

        MemberAction(T* instance, FuncT func){
            this->instance = instance;
            this->func = func;
        };

        T* getInstance(){
            return instance;
        }

        void operator()(Key key) override {
            (instance->*func)(key);
        }

    private:
        T* instance;
        FuncT func;
};

}

#endif