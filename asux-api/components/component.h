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

#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

// Macros to simplify the declarative syntax inside the build() method
#define _this &((*this))
#define _(T) &((*new T()))

#include "properties/position.h"
#include "properties/size.h"
#include "properties/padding.h"
#include "properties/margin.h"
#include "../action.h"

#include <vector>
#include <functional>
#include <map>

using namespace std;

namespace ASUX {

class UIComponent {
    protected:
        Position _position;
        Size _size;
        Margin _margin;
        Padding _padding;
        bool _visibility;
        
    public:
        vector<UIComponent*> children;
        multimap<Key, Action*> actions;

        UIComponent(Position position = Position::Default);
        virtual ~UIComponent(){};  // Required for using it as an item in <vector>.
        
        virtual bool getVisibility() const;
        virtual const Position& getPosition() const;

        virtual const Size& getSize() const;
        virtual unsigned getWidth() const;
        virtual unsigned getHeight() const;

        virtual const Padding& getPadding() const;
        virtual unsigned getPaddingTop() const;
        virtual unsigned getPaddingBottom() const;
        virtual unsigned getPaddingLeft() const;
        virtual unsigned getPaddingRight() const;

        virtual const Margin& getMargin() const;
        virtual unsigned getMarginTop() const;
        virtual unsigned getMarginBottom() const;
        virtual unsigned getMarginLeft() const;
        virtual unsigned getMarginRight() const;

        virtual UIComponent& visibility(bool value);
        virtual UIComponent& position(Position position);

        virtual UIComponent& size(Size& size);
        virtual UIComponent& width(unsigned value);
        virtual UIComponent& height(unsigned value);

        virtual UIComponent& padding(Padding& padding);
        virtual UIComponent& padding(unsigned top, unsigned bottom, unsigned left, unsigned right);
        virtual UIComponent& paddingTop(unsigned value);
        virtual UIComponent& paddingBottom(unsigned value);
        virtual UIComponent& paddingLeft(unsigned value);
        virtual UIComponent& paddingRight(unsigned value);

        virtual UIComponent& margin(Margin& margin);
        virtual UIComponent& margin(unsigned top, unsigned bottom, unsigned left, unsigned right);
        virtual UIComponent& marginTop(unsigned value);
        virtual UIComponent& marginBottom(unsigned value);
        virtual UIComponent& marginLeft(unsigned value);
        virtual UIComponent& marginRight(unsigned value);

        template <typename T>
        UIComponent& onKey(Key key, void (T::*func)(Key), T* instance){
            actions.insert({key, new MemberAction<T>(instance, func)});
            return *this;
        }
        virtual const vector<UIComponent*> build() = 0;
};

}

#endif