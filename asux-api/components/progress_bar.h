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

#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include "raw_component.h"
#include "properties/color.h"

namespace ASUX {

class ProgressBar: public RawComponent {
    private:
        unsigned _progress;
        bool showPercentage;
    public:
        ProgressBar(unsigned width = 5, unsigned height = 1, Position position = Position::Default);
        unsigned getProgress() const;
        ProgressBar& progress(unsigned value);
        void increaseProgress(unsigned value);
        void decreaseProgress(unsigned value);
        ProgressBar& percentageVisibility(bool value);
        const string* render() const override;
};

}

#endif