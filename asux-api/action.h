#ifndef ACTION_H
#define ACTION_H

#include "key.h"

namespace ASUX {

class Action {
    public:
        virtual ~Action() = default;
        virtual void call(Key value) = 0;
};

template <typename T>
class MemberAction : public Action {
    private:
        T* instance;
        FuncT func;
    public:
        using FuncT = void (T::*)(Key key);

        MemberAction(T* instance, FuncT func){
            this->instance = instance;
            this->func = func;
        };

        void call(Key key) override {
            (instance->*func)(key);
        }
};

}

#endif