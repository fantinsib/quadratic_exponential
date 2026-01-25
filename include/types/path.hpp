
#include <vector>
#include <optional>

#include "state.hpp"

struct Path{

    std::vector<State> states;

    State end_value() {return states.back();}
    float size() {return states.size();}
    void set_size(size_t size) {
        states.reserve(size);
    };
    void set_step(State state, int i) {
        states[i] = state;
    }
};


