#ifndef EXAMPLE_COMPONENT_H
#define EXAMPLE_COMPONENT_H

#include "ASUX/components/components.h"

using namespace ASUX;

class ExampleComponent: public UIComponent {
    public:
        const vector<UIComponent*> build() override {
            return {
                
            };
        }
};

#endif