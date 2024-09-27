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

#include "progress_bar.h"

#include <string>
#include <iostream>

using namespace ASUX;
using namespace std;

ProgressBar::ProgressBar(unsigned width, unsigned height, Position position): UIComponent(position){
    this->_size = {width, height};
    this->_progress = 0;
}

Color ProgressBar::getColor() const {
    return this->_color;
}

unsigned ProgressBar::getProgress() const {
    return this->_progress;
}

ProgressBar& ProgressBar::color(Color color){
    this->_color = color;
    return *this;
}

ProgressBar& ProgressBar::progress(unsigned value){
    if(value <= 100) this->_progress = value;
    else this->_progress = 100;
    return *this;
}

void ProgressBar::increaseProgress(unsigned value){
    if(this->_progress + value > 100) this->_progress = 100;
    else _progress += value;
}

void ProgressBar::decreaseProgress(unsigned value){
    if(this->_progress - value < 0) this->_progress = 0;
    else this->_progress -= value;
}

ProgressBar& ProgressBar::percentageVisibility(bool value){
    this->showPercentage = value;
    return *this;
}

void ProgressBar::render() const {
    // Calculate the number of progress bar blocks
    double blockStep = (double) (1.0 * _size.width) / 100;
    unsigned filledBlocks = blockStep * _progress;
    unsigned emptyBlocks = _size.width - filledBlocks;

    // Build the progress bar UI
    string progressBar = "";
    for(unsigned i = 0; i < filledBlocks; i++) progressBar += "█";
    for(unsigned i = 0; i < emptyBlocks; i++) progressBar += " ";


    // Render
    for(unsigned i = 0; i < _size.height; i++){
        cout << toANSICode(_color) << progressBar << "▏" << toANSICode(Color::Default);
        cout << (((i+1 == _size.height / 2 && !(_size.height % 2)) || 
                (i == _size.height / 2 && (_size.height % 2))) &&
                showPercentage ? to_string(_progress) + "%": "") << endl;
    }
}

const vector<UIComponent*> ProgressBar::build(){
    return {};
}