#pragma once

#include <vector>
#include <optional>

#include "state.hpp"


/**
 * @brief Struct containing a vector of States 
 * representing the evolution of the asset over
 * the simulation. 
 * 
 */
struct Path{

    std::vector<State> states;

    State end_state() {return states.back();}
    float size() {return states.size();}
    void set_size(size_t size) {
        states.resize(size);
    };
    void set_step(State state, int i) {
        states[i] = state;
    }
};


