#include "schemes.hpp"
#include "models/black_scholes/black_scholes.hpp"
#include "schemes/state.hpp"

#include <optional>
#include <random>


class EulerBlackScholes : Scheme 
{

    public:
    EulerBlackScholes(BlackScholes model):
    model(model)
    {};

    BlackScholes model;

    State init_state(float S0);

    State step(State state, float dt, std::mt19937 rng);

};