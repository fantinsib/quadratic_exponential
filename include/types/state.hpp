#pragma once

#include <optional>

struct State {

    float S;
    std::optional<float> v = std::nullopt;

    float spot() const {return S;}
    float vol() {
        if (v.has_value()) {
            return v.value();
        }
        else return -1; 
}

};