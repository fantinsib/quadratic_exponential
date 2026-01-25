
/*
 _            _                               _                        _       
| |_ ___  ___| |_ ___   _ __ ___   ___  _ __ | |_ ___    ___ __ _ _ __| | ___  
| __/ _ \/ __| __/ __| | '_ ` _ \ / _ \| '_ \| __/ _ \  / __/ _` | '__| |/ _ \ 
| ||  __/\__ \ |_\__ \ | | | | | | (_) | | | | ||  __/ | (_| (_| | |  | | (_) |
 \__\___||___/\__|___/ |_| |_| |_|\___/|_| |_|\__\___|  \___\__,_|_|  |_|\___/ 
                                                                 
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>  
#include "models/black_scholes/black_scholes.hpp"
#include "schemes/eulerblackscholes.hpp"
#include "engine/montecarlo.hpp"



TEST_CASE("Monte Carlo - BlackScholes & Euler - basic usage"){

    BlackScholes bs{0.02, 0.1};
    EulerBlackScholes eu_scheme(bs);
    MonteCarlo mc(eu_scheme);

    mc.set_seed(1);

    Path simulation= mc.simulate(100, 252, 1);

    REQUIRE(simulation.size() == 252);
    REQUIRE(simulation.end_state().spot() != 100);

}
