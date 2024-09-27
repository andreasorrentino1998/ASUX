/**
* ASUX: a mini C++ framework for creating interactive 
* user interfaces for terminal-based applications.
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

#include "component.h"
#include "properties/color.h"

namespace ASUX {

class ProgressBar: public UIComponent {
    private:
        unsigned _progress;
        bool showPercentage;
        Color _color;
    public:
        ProgressBar(unsigned width = 5, unsigned height = 1, Position position = Position::Default);
        Color getColor() const;
        unsigned getProgress() const;
        ProgressBar& color(Color color);
        ProgressBar& progress(unsigned value);
        void increaseProgress(unsigned value);
        void decreaseProgress(unsigned value);
        ProgressBar& percentageVisibility(bool value);
        void render() const override;
        const vector<UIComponent*> build() override;
};

}

#endif