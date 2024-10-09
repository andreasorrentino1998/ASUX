#ifndef INPUT_H
#define INPUT_H

#include "components/component.h"
#include "terminal.h"
#include "key.h"

namespace ASUX {

namespace Input {

    Key getInputKey();
    UIComponent* triggerActions(const UIComponent *component, Key key);

}

}

#endif