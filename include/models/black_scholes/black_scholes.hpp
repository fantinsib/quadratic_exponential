#pragma once

#include "models/model.hpp"
#include <stdexcept>



/**
 * @brief Base class for the Black Scholes model
 */

struct BlackScholes : Model {
    BlackScholes(float mu, float sigma) : 
        mu(mu),
        sigma(sigma) {
            if (sigma < 0) throw std::invalid_argument("Black-Scholes Constructor : sigma must be strictly positive");
        }

    float mu; 
    float sigma; 
};
