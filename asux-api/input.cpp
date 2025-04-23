#include "input.h"
#include "action.h"

using namespace ASUX;

UIComponent* Input::triggerActions(const UIComponent *component, Key key){
    UIComponent *dirtyComponent = nullptr;          // On-top dirty component
    UIComponent *triggerComponent = nullptr;        // The component which triggered the action

    // TODO: If Key is a letter, handle the case insensitiveness of the action
    if((key >= Key::A && key <= Key::Z) || (key >= Key::a && key <= Key::z));

    // Trigger actions defined on the focused component child
    const UIComponent* child = component->getFocusedComponent();
    if(child != nullptr) triggerComponent = triggerActions(child, key);
    if(triggerComponent != nullptr) dirtyComponent = triggerComponent;

    // Trigger actions defined on the current component
    auto range = component->getActions().equal_range(key);
    for(auto it = range.first; it != range.second; it++){
        (*it->second)(key);
        dirtyComponent = (*it->second).getInstance();
    }

    // Trigger "AnyKey-Event" actions
    range = component->getActions().equal_range(Key::Any);
    for(auto it = range.first; it != range.second; it++){
        (*it->second)(key);
        dirtyComponent = (*it->second).getInstance();
    }

    // TODO: Think to a better software design ===============
    auto range2 = component->getIndexedActions().equal_range(key);
    for(auto it = range2.first; it != range2.second; it++){
        (*it->second).func((*it->second).index);
        dirtyComponent = (*it->second).instance;
    }

    // Trigger "AnyKey-Event" indexed actions
    range2 = component->getIndexedActions().equal_range(Key::Any);
    for(auto it = range2.first; it != range2.second; it++){
        (*it->second).func((*it->second).index);
        dirtyComponent = (*it->second).instance;
    }
    // =========================

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

    if(buffer[0] == ASCIIKey::Backspace || buffer[0] == ASCIIKey::Delete) return Key::Backspace;

    if(buffer[0] == ASCIIKey::Slash) return Key::Slash;
    
    if(buffer[0] == ASCIIKey::LineFeed && buffer[1] == ASCIIKey::Null) return Key::Enter; // UNIX (Linux, macOS)
    else if(buffer[0] == ASCIIKey::CarriageReturn && buffer[1] == ASCIIKey::LineFeed) return Key::Enter; // Windows

    if((buffer[0] >= ASCIIKey::A && buffer[0] <= ASCIIKey::Z) || (buffer[0] >= ASCIIKey::a && buffer[0] <= ASCIIKey::z) ||
    (buffer[0] >= ASCIIKey::N0 && buffer[0] <= ASCIIKey::N9) || (buffer[0] == ASCIIKey::Space))
        return static_cast<Key>(buffer[0]);
    
    delete buffer;

    return Key::Null;
}