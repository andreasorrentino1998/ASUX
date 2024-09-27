#include "color.h"

using namespace ASUX;

namespace ASUX{

Color& operator+=(Color& color, int value){
    if(value > 0){
        int id = color + value;
        if(id == 8) return color = Color::Default;
        else if(id > Color::Default) return color = Color::Black;
        else return color = (Color) id;
    }
    if(value < 0){
        int id = color + value;
        if(id == 8) return color = Color::White;
        else if(id < Color::Black) return color = Color::Default;
        else return color = (Color) id;
    } 
    else return color;
}

Color& operator-=(Color& color, int value){
    return color += -value;
}

string toString(Color color){
    string colorStrings[10] = {
        "Black",
        "Red",
        "Green",
        "Yellow",
        "Blue",
        "Magenta",
        "Cyan",
        "White",
        "",
        "Default"
    };
    return colorStrings[color];
}

}