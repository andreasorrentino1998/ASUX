#ifndef EXAMPLE_VIEW_H
#define EXAMPLE_VIEW_H

#include "ASUX/components/components.h"

using namespace ASUX;

class ExampleView: public View {
    public:
        ExampleView(){
            _this
                .title("EXAMPLE VIEW");
        }

        const vector<UIComponent*> build() override {
            return {
                
            };
        }
};

#endif