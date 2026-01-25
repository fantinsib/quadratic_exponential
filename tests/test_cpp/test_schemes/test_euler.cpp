/*
 _            _         _____      _           
| |_ ___  ___| |_ ___  | ____|   _| | ___ _ __ 
| __/ _ \/ __| __/ __| |  _|| | | | |/ _ \ '__|
| ||  __/\__ \ |_\__ \ | |__| |_| | |  __/ |   
 \__\___||___/\__|___/ |_____\__,_|_|\___|_|   
                                              
*/



#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>  
#include "models/black_scholes/black_scholes.hpp"
#include "models/heston/heston.hpp"
#include "schemes/eulerblackscholes.hpp"


TEST_CASE("Scheme - EulerBlackScholes") {

SECTION("Constructor") {

    BlackScholes bs{0.02, 0.2};
    EulerBlackScholes euler_bs{bs};

    std::mt19937 rng;
    float dt = 0.1;
    State init{100};

    State S{euler_bs.step(init, dt, rng)};
    REQUIRE(S.spot());

}

}
