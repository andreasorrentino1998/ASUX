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

#ifndef APP_H
#define APP_H

#include "navigator.h"
#include "view_factory.h"
#include "components/component.h"
#include "runnable.h"
#include "task.h"

#include <deque>
#include <mutex>
#include <atomic>

namespace ASUX {

using namespace std;

class App {
    private:
        App *instance;
        Navigator *navigator;
        vector<PeriodicTask> tasks;
        
        mutex queueMutex;
        deque<Key> keyEventsQueue;
        atomic<bool> shouldExit{false};
        
        App();
        void eventLoop();
    public:
        static App* init(IViewFactory *viewFactory);
        void setRootView(string viewID);
        void registerRunnable(Runnable& runnable);
        void refresh(UIComponent *component);
        void runLoop();
};

}

#endif