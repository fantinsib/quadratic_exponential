#include "schemes.hpp"
#include "models/black_scholes/black_scholes.hpp"
#include "types/state.hpp"

#include <optional>
#include <random>



/**
 * @brief Scheme for the discretization of the Black Scholes
 * model with log Euler method. 
 *
 * @param model : a BlackScholes model 
 *
 */
class EulerBlackScholes : public Scheme 
{

    public:
    EulerBlackScholes(BlackScholes model):
    model(model)
    {};

    BlackScholes model;

    State init_state(float S0, std::optional<float> v0) const override;

    State step(const State& state, float dt, std::mt19937& rng) const override;

};