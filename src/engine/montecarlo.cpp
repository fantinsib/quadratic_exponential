


#include "types/path.hpp"
#include "engine/montecarlo.hpp"
#include "types/state.hpp"
#include <random>




Path MonteCarlo::simulate(float S0, int n, float T, std::optional<float> v0){

    float dt = T/static_cast<float>(n);
    State state = scheme_.init_state(S0, v0);
    Path path; 
    path.set_size(static_cast<size_t>(n));
    path.set_step(state, 0);

    std::mt19937 rng(seed_);

    for (int step = 1; step < n; step ++){

        state = scheme_.step(state, dt, rng);
        path.set_step(state, step);

    }

    return path;
}