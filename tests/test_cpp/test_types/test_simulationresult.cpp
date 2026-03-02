


#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>  
#include <memory>
#include <optional>
#include <stdexcept>

#include <types/simulationresult.hpp>
#include <vector>


TEST_CASE("SimulationResult - Basic usage"){

    std::vector<double> my_path{100, 101, 102, 103,
                                   100, 99, 98, 97};

    SECTION("Constructor") {
        SimulationResult res(std::make_shared<std::vector<double>>(my_path),  1, 3, 2, 1);
    }

    SECTION("Dimension errors") {
        REQUIRE_THROWS_AS(SimulationResult(std::make_shared<std::vector<double>>(my_path),  1, 2, 2, 1), std::invalid_argument);
    }

    SECTION("Access to data") {
        SimulationResult res( std::make_shared<std::vector<double>>(my_path),  1, 3, 2,1);
        const std::vector<double>& paths = res.get_paths();

    }

}


TEST_CASE("SimulationResult - Average terminal value") {

    std::vector<double> my_path{100, 101, 102, 103,
                                   100, 99, 98, 103,
                                100, 99, 101, 103};

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 3, 3,1);

    REQUIRE(res.avg_terminal_value() == 103.0);

}


TEST_CASE("SimulationResult - Error accessing vol") {

    std::vector<double> my_path{100, 101, 102, 103,
                                   100, 99, 98, 103,
                                100, 99, 101, 103};

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 3, 3,1);

    REQUIRE_THROWS_AS(res.get_vol(), std::invalid_argument);

}

TEST_CASE("SimulationResult - Error on T") {
        std::vector<double> my_path{100, 101, 102, 103,
                                   100, 99, 98, 103,
                                100, 99, 101, 103};
        REQUIRE_THROWS_AS(SimulationResult(std::make_shared<std::vector<double>>(my_path), 1, 3, 3,-1), std::invalid_argument);

}


TEST_CASE("SimulationResut - Get spot at t") {

    std::vector<double> my_path{100, 101, 102, 103,
                                100, 99, 98, 97,
                                100, 99, 101, 102,
                                100, 95, 90, 80};

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 3, 4,1);

    SECTION("t = 2"){
        std::vector<double> spots = res.get_spot_at(2);
        
        REQUIRE(spots[0] == 102.0);
        REQUIRE(spots[1] == 98.0);
        REQUIRE(spots[2] == 101.0);
        REQUIRE(spots[3] == 90.0);

    }

    SECTION("t = 0"){
        std::vector<double> spots = res.get_spot_at(0);
        
        REQUIRE(spots[0] == 100.0);
        REQUIRE(spots[1] == 100.0);
        REQUIRE(spots[2] == 100.0);
        REQUIRE(spots[3] == 100.0);

    }

    SECTION("t = end"){
        std::vector<double> spots = res.get_spot_at(3);
        
        REQUIRE(spots[0] == 103);
        REQUIRE(spots[1] == 97);
        REQUIRE(spots[2] == 102);
        REQUIRE(spots[3] == 80);

    }

    SECTION("t oob"){
        REQUIRE_THROWS_AS(res.get_spot_at(4), std::invalid_argument);
    }
    



}