#include "schemes.hpp"
#include "models/heston/heston.hpp"
#include "types/state.hpp"

#include <optional>
#include <random>




class Euler : public Scheme {

    public:
    Euler(Model model):
    model_(model) {};

    /**
    * @brief Creates the initial state at time 0
    * 
    *
    * @param S0 the spot at time 0
    * 
    * @return State : a State object representing the initial state
    */
    State init_state(float S0, std::optional<float> v0) const override;


    State step(const State& state, float dt, std::mt19937& rng) const override;
    private:
    Model model_;

};