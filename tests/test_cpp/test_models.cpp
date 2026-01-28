
/*
 _            _                             _      _     
| |_ ___  ___| |_ ___   _ __ ___   ___   __| | ___| |___ 
| __/ _ \/ __| __/ __| | '_ ` _ \ / _ \ / _` |/ _ \ / __|
| ||  __/\__ \ |_\__ \ | | | | | | (_) | (_| |  __/ \__ \
 \__\___||___/\__|___/ |_| |_| |_|\___/ \__,_|\___|_|___/

*/


#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>  
#include "models/black_scholes/black_scholes.hpp"
#include "models/heston/heston.hpp"



TEST_CASE("Models - Black Scholes - constructor"){

    SECTION("Valid arguments"){
            BlackScholes bs = BlackScholes{0.02, 0.2};
            BlackScholes bs_zero = BlackScholes{0.02, 0.0};
    }

    SECTION("Invalid arguments"){
        REQUIRE_THROWS_AS((BlackScholes{0.02, -0.1}), std::invalid_argument);
    }

}


TEST_CASE("Models - Heston - constructor"){

    SECTION("Valid arguments"){
            Heston heston = Heston{0.02, 2, 0.05, 0.1, 0.7};
    }

    SECTION("Invalid arguments"){

        REQUIRE_THROWS_AS((Heston{0.02, 0, 0.05, 0.1, 0.7}), std::invalid_argument);
        REQUIRE_THROWS_AS((Heston{0.02, 2, -0.05, 0.1, 0.7}), std::invalid_argument);
        REQUIRE_THROWS_AS((Heston{0.02, 2, 0.05, -0.1, 0.7}), std::invalid_argument);
        REQUIRE_THROWS_AS((Heston{0.02, 2, 0.05, 0.1, 1.1}), std::invalid_argument);
        REQUIRE_THROWS_AS((Heston{0.02, -1, 0.05, 0.1, 0.7}), std::invalid_argument);
        REQUIRE_THROWS_AS((Heston{0.02, 2, 0.05, 0.1, -1.1}), std::invalid_argument);
    }

    SECTION("Feller Condition"){
        Heston heston_feller_true = Heston{0.02, 2, 0.05, 0.1, 0.7};
        Heston heston_feller_false = Heston{0.02, 1, 0.01, 0.25, 0.7};
        
        REQUIRE(heston_feller_true.feller_condition() == true);
        REQUIRE(heston_feller_false.feller_condition() == false);

    }

    SECTION("Rho boundaries"){
        REQUIRE_NOTHROW((Heston{0.02, 2, 0.05, 0.1, -1.0}));
        REQUIRE_NOTHROW((Heston{0.02, 2, 0.05, 0.1, 1.0}));
    }

}
