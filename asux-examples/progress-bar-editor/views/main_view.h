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

#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include "ASUX/components/components.h"
#include "../models/progress_bar_model.h"

using namespace ASUX;

class MainView: public View {
    private:
        ProgressBarModel model = {20, 1, 40, Color::Blue, true};
        const string optionLabels[5] = { "Progress", "Color", "Width", "Height", "Show percentage"};
        const string optionDescriptions[5] = {
            "This option change the progress state.",
            "This option change the progress bar color.",
            "This option change the progress bar width.",
            "This option change the progress bar height.",
            "This option show/hide the progress bar percentage."
        };
        bool confirmed = false;
        bool optionInfoVisibility = false;
    public:
        MainView(){
            _this
                .title("PROGRESS BAR EDITOR")
                .onKey(Key::Left, &MainView::changeOptionValue, this)
                .onKey(Key::Right, &MainView::changeOptionValue, this);
        }

        void confirmOptions(Key key){
            confirmed = true;
        }

        void showHideOptionInfo(Key key){
            optionInfoVisibility = !optionInfoVisibility;
        }

        void changeOptionValue(Key key){
            int increase = -1;
            if(key == Key::Right) increase = 1;
            
            if(_y == 0 && ((key == Key::Right && model.progress < 100) || (key == Key::Left && model.progress))) model.progress += increase;
            else if(_y == 1) model.color += increase;
            else if(_y == 2 && (key == Key::Right || model.width)) model.width += increase;
            else if(_y == 3 && (key == Key::Right || model.height)) model.height += increase;
            else if(_y == 4) model.showPercentage = !model.showPercentage;

            confirmed = false;
        }

        string getOptionValueString(unsigned index){
            string values[5] = {
                to_string(model.progress) + "%",
                toString(model.color),
                to_string(model.width),
                to_string(model.height),
                model.showPercentage? "Yes": "No"
            };
            return values[index];
        }

        const vector<UIComponent*> build() override {
            return {
                _(Text)
                    .text("Edit the progress bar parameters."),
                _(List)
                    .itemsCount(5)
                    _builder(
                    _(Option)
                        .title(optionLabels[i])
                        .value(getOptionValueString(i))
                        .focusable(true)
                        .onKey(Key::I, &MainView::showHideOptionInfo, this)
                    ),
                _(ProgressBar)
                    .progress(model.progress)
                    .percentageVisibility(model.showPercentage)
                    .width(model.width)
                    .height(model.height)
                    .color(model.color),
                _(Text)
                    .text(this->_y < 5? optionDescriptions[this->_y]: "")
                    .visibility(this->_y < 5 && optionInfoVisibility),
                _(Button)
                    .text("Save")
                    .padding(1, 1, 2, 2)
                    .onKey(Key::Enter, &MainView::confirmOptions, this)
                    .focusable(true),
                _(Text)
                    .text("Options saved successfully.")
                    .color(Color::Green)
                    .visibility(confirmed)
                    .margin(1, 0, 0, 0)
            };
        }
};

#endif