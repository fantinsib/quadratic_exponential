


#include "types/path.hpp"
#include "engine/montecarlo.hpp"
#include "types/state.hpp"




Path MonteCarlo::simulate(float S0, int n, float T, std::optional<float> v0){

    float dt = T/static_cast<float>(n);
    State state = scheme.init_state(S0, v0);
    Path path; 
    path.set_size(static_cast<size_t>(n));

    for (int step = 0; step < n; step ++){


        path.set_step(state, step);

    }

}