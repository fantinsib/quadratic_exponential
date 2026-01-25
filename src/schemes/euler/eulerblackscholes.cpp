#include "schemes/eulerblackscholes.hpp"
#include "models/black_scholes/black_scholes.hpp"
#include "schemes/schemes.hpp"
#include "schemes/state.hpp"
#include <random>
#include <random>




State EulerBlackScholes::init_state(float S0){

    State state{S0};
    return state;
    
}

State EulerBlackScholes::step(State state, float dt, std::mt19937 rng) {

    std::normal_distribution<float> dist;
    
    float S = state.spot();
    float Z = dist(rng);
    float r = model.mu * dt + model.sigma*Z;

    return State{S * (1+r)};
}

