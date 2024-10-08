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

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "components/view.h"
#include "components/navigation_bar.h"

#include <stack>                    // Provides: stack

using namespace std;

namespace ASUX {

// Forward declaration (to solve circular-dependency)
// TODO: Think of a better software design to solve that.
class View;

class Navigator {
    private:
        stack<View*> viewStack;
        NavigationBar navigationBar;
        bool navigationBarVisibility;
    public:
        Navigator();
        NavigationBar& getNavigationBar();     // TODO: think about const and renderer
        View* getCurrentView();
        bool navigationBarShouldBeRendered() const;
        void setNavigationBarVisibility(const bool value);
        void navigateTo(View *view);
        void navigateBack();
};

}

#endif