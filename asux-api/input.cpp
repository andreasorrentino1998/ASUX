#include "input.h"
#include "action.h"

using namespace ASUX;

UIComponent* Input::triggerActions(UIComponent *component, Key key){
    // Ontop dirty component
    UIComponent *dirtyComponent = nullptr;

    // Trigger actions on the component children
    const vector<UIComponent*> children = component->children;
    for(unsigned i = 0; i < children.size(); i++){
        UIComponent *triggerComponent = triggerActions(children[i], key);
        if(triggerComponent != nullptr) dirtyComponent = triggerComponent;
    }

    // Trigger action on the current component
    auto range = component->actions.equal_range(key);
    for(auto it = range.first; it != range.second; it++){
        (*it->second)(key);
        dirtyComponent = (*it->second).getInstance();
    }

    return dirtyComponent;
}

Key Input::getInputKey(){
    // Get the character buffer from the terminal
    char *buffer = Terminal::getChar(6);

    // Convert ASCII char sequence into an ASUX Key
    if(buffer[0] == ASCIIKey::ESC && buffer[1] == ASCIIKey::LeftBracket){
        switch(buffer[2]){
            case ASCIIKey::A:
                return Key::Up;
                break;
            case ASCIIKey::B:
                return Key::Down;
                break;
            case ASCIIKey::C:
                return Key::Right;
                break;
            case ASCIIKey::D:
                return Key::Left;
                break;
        }
    }
    else if(buffer[0] == ASCIIKey::ESC && buffer[1] == ASCIIKey::Null) return Key::ESC;
    
    if(buffer[0] == ASCIIKey::LineFeed && buffer[1] == ASCIIKey::Null) return Key::Enter; // UNIX (Linux, macOS)
    else if(buffer[0] == ASCIIKey::CarriageReturn && buffer[1] == ASCIIKey::LineFeed) return Key::Enter; // Windows

    if(buffer[0] > ASCIIKey::A && buffer[0] < ASCIIKey::Z) return static_cast<Key>(buffer[0]);
    if(buffer[0] > ASCIIKey::a && buffer[0] < ASCIIKey::z) return static_cast<Key>(toupper(buffer[0]));
    
    delete buffer;

    return Key::Null;
}