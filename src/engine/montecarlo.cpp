


#include "types/path.hpp"
#include "engine/montecarlo.hpp"
#include "types/simulationresult.hpp"
#include "types/state.hpp"
#include <optional>
#include <random>




Path MonteCarlo::simulate_path(float S0, size_t n, float T, std::optional<float> v0){

    float dt = T/static_cast<float>(n);
    State state = scheme_->init_state(S0, v0);
    Path path; 
    path.set_size(static_cast<size_t>(n));
    path.set_step(state, 0);

    for (size_t step = 1; step < n; step ++){

        state = scheme_->step(state, dt, rng_);
        path.set_step(state, step);
    }

    return path;
}

SimulationResult MonteCarlo::generate(float S0, size_t n, float T, size_t n_paths, std::optional<float> v0){

    auto bundle= std::make_shared<PathBundle>();
    bundle->n_paths = n_paths;
    bundle->n_steps = n;

    const size_t M = n_paths * (n+1);
    bundle->spot.resize(M);
    bundle->var.resize(M);

    float dt = T/static_cast<float>(n);

    for (size_t p = 0; p < n_paths; p++){

        State state = scheme_->init_state(S0, v0);
        bundle->spot[(p*(n+1))] = state.spot();
        bundle->var[(p*(n+1))] = state.vol().value();


        for (size_t step = 0; step < n; step++){

            State s = scheme_->step(state, dt, rng_);
            bundle->spot[(p*(n+1))+(step+1)] = s.spot();
            bundle->var[(p*(n+1))+(step+1)] = s.vol().value();
            state = s;
        }

    }
    return SimulationResult{seed_, n_paths, n,bundle}; 
}