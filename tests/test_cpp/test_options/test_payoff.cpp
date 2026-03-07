

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>  
#include <memory>
#include <stdexcept>
#include "payoff/extractor.h"
#include "payoff/observationschedule.h"
#include "types/simulationresult.hpp"



TEST_CASE("ObservationSchedule - Constructor") {

    std::vector<double> observe_at_time{0.2, 0.3, 0.8,0.9};
    ObservationSchedule schedule{observe_at_time};
}



TEST_CASE("Extractor - Constructor") {

    std::vector<double> my_path{100, 101, 102, 103,
                                100, 99, 98, 97,
                                100, 99, 101, 102,
                                100, 95, 90, 80};

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 3, 4,1);

    Extractor extr(std::make_shared<SimulationResult>(res));

}


TEST_CASE("Extractor - Timeframe to index") {
                            //t : 0       0.25      0.5    0.75         1
    std::vector<double> my_path{100, 101, 102, 103, 105,
                                100, 99, 98, 97, 99,
                                100, 99, 101, 102, 104,
                                100, 95, 90, 80, 70};

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 4, 4,1);

    Extractor extr(std::make_shared<SimulationResult>(res));

    std::vector<double> dates {0.1, 0.5, 0.9, 0.95};

    std::vector<size_t> idx = extr.tf_to_index(dates);

    REQUIRE(idx[0] == 1);
    REQUIRE(idx[1] == 2);
    REQUIRE(idx[2] == 4);
    REQUIRE(idx[3] == 4);

}

TEST_CASE("Extractor - observation at later date than maturity") {
                            //t : 0       0.25      0.5    0.75         1
    std::vector<double> my_path{100, 101, 102, 103, 105,
                                100, 99, 98, 97, 99,
                                100, 99, 101, 102, 104,
                                100, 95, 90, 80, 70};

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 4, 4,1);

    Extractor extr(std::make_shared<SimulationResult>(res));

    std::vector<double> dates {0.1, 0.5, 0.9, 1.1};

    REQUIRE_THROWS_AS(extr.tf_to_index(dates), std::invalid_argument);

}

TEST_CASE("Extractor - accessing spots at time t") {
                            //t : 0       0.25      0.5    0.75         1
    std::vector<double> my_path{100, 101, 102, 103, 105,
                                100, 99, 98, 97, 99,
                                100, 99, 101, 102, 104,
                                100, 95, 90, 80, 70};

    int n_paths = 4;

    SimulationResult res(std::make_shared<std::vector<double>>(my_path), 1, 4, n_paths,1);

    Extractor extr(std::make_shared<SimulationResult>(res));

    std::vector<double> dates {0, 0.1, 0.5, 0.9};

    ObservationSchedule schedule{dates};

    Extractor extract{std::make_shared<SimulationResult>(res)};

    std::vector<std::vector<double>> observed = extract.get(schedule);

    for (size_t i = 0; i < n_paths; i++) {
        REQUIRE(observed[0][i] == 100.0);
    }

    REQUIRE(observed[1][0] == 101);
    REQUIRE(observed[1][1] == 99);
    REQUIRE(observed[1][2] == 99);
    REQUIRE(observed[1][3] == 95);

    REQUIRE(observed[2][0] == 102);
    REQUIRE(observed[2][1] == 98);
    REQUIRE(observed[2][2] == 101);
    REQUIRE(observed[2][3] == 90);

}
