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

#include "component.h"

using namespace ASUX;

UIComponent::UIComponent(Position position){
    this->_position = position;
    this->_padding = {0, 0, 0, 0};
    this->_margin = {0, 0, 0, 0};
    this->_visibility = true;
    this->actions = map<Key, Action*>();
}

bool UIComponent::getVisibility() const {
    return this->_visibility;
}

const Position& UIComponent::getPosition() const {
    return this->_position;
}

const Size& UIComponent::getSize() const {
    return this->_size;
}

unsigned UIComponent::getWidth() const {
    return this->_size.width;
}

unsigned UIComponent::getHeight() const {
    return this->_size.height;
}

const Margin& UIComponent::getMargin() const {
    return this->_margin;
}

unsigned UIComponent::getMarginTop() const {
    return this->_margin.top;
}

unsigned UIComponent::getMarginBottom() const {
    return this->_margin.bottom;
}

unsigned UIComponent::getMarginLeft() const {
    return this->_margin.left;
}

unsigned UIComponent::getMarginRight() const {
    return this->_margin.right;
}

const Padding& UIComponent::getPadding() const {
    return this->_padding;
}

unsigned UIComponent::getPaddingTop() const {
    return this->_padding.top;
}

unsigned UIComponent::getPaddingBottom() const {
    return this->_padding.bottom;
}

unsigned UIComponent::getPaddingLeft() const {
    return this->_padding.left;
}

unsigned UIComponent::getPaddingRight() const {
    return this->_padding.right;
}

UIComponent& UIComponent::visibility(bool value){
    this->_visibility = value;
    return *this;
}

UIComponent& UIComponent::position(Position position){
    this->_position = position;
    return *this;
}

UIComponent& UIComponent::size(Size& size){
    this->_size = {size.width, size.height};
    return *this;
}

UIComponent& UIComponent::width(unsigned value){
    this->_size.width = value;
    return *this;
}

UIComponent& UIComponent::height(unsigned value){
    this->_size.height = value;
    return *this;
}

UIComponent& UIComponent::padding(Padding& padding){
    this->_padding = {padding.top, padding.bottom, padding.left, padding.right};
    return *this;
}

UIComponent& UIComponent::padding(unsigned top, unsigned bottom, unsigned left, unsigned right){
    this->_padding = {top, bottom, left, right};
    return *this;
}

UIComponent& UIComponent::paddingTop(unsigned value){
    this->_padding.top = value;
    return *this;
}

UIComponent& UIComponent::paddingBottom(unsigned value){
    this->_padding.bottom = value;
    return *this;
}

UIComponent& UIComponent::paddingLeft(unsigned value){
    this->_padding.left = value;
    return *this;
}

UIComponent& UIComponent::paddingRight(unsigned value){
    this->_padding.right = value;
    return *this;
}

UIComponent& UIComponent::margin(Margin& margin){
    this->_margin = {margin.top, margin.bottom, margin.left, margin.right};
    return *this;
}

UIComponent& UIComponent::margin(unsigned top, unsigned bottom, unsigned left, unsigned right){
    this->_margin = {top, bottom, left, right};
    return *this;
}

UIComponent& UIComponent::marginTop(unsigned value){
    this->_margin.top = value;
    return *this;
}

UIComponent& UIComponent::marginBottom(unsigned value){
    this->_margin.bottom = value;
    return *this;
}

UIComponent& UIComponent::marginLeft(unsigned value){
    this->_margin.left = value;
    return *this;
}

UIComponent& UIComponent::marginRight(unsigned value){
    this->_margin.right = value;
    return *this;
}
