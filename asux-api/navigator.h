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

#include "navigator_service.h"
#include "view_factory.h"
#include "components/navigation_bar.h"

#include <stack>                    // Provides: stack

using namespace std;

namespace ASUX {

class Navigator: public NavigatorService {
    private:
        IViewFactory* viewFactory;
        stack<View*> viewStack;
        vector<string> viewIDStack;
        NavigationBar navigationBar;
        bool navigationBarVisibility;
    public:
        Navigator(IViewFactory* viewFactory);
        NavigationBar& getNavigationBar();     // TODO: think about const and renderer
        View* getCurrentView();
        bool navigationBarShouldBeRendered() const;
        void setNavigationBarVisibility(const bool value);
        void navigateTo(string viewID) override;
        void navigateBack() override;
};

}

#endif