/*
 _            _     ____        _       
| |_ ___  ___| |_  |  _ \  __ _| |_ ___ 
| __/ _ \/ __| __| | | | |/ _` | __/ _ \
| ||  __/\__ \ |_  | |_| | (_| | ||  __/
 \__\___||___/\__| |____/ \__,_|\__\___|
*/

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>  
#include <optional>
#include <stdexcept>

#include <types/date.hpp>


TEST_CASE("Date - Basis usage") {

    Date my_date(1, 12, 2026);

    REQUIRE(my_date.month() == 12);
    REQUIRE(my_date.day() == 1);
    REQUIRE(my_date.year() == 2026);
    REQUIRE(my_date.second() == 0);
    REQUIRE(my_date.hour() == 0);
    REQUIRE(my_date.minute() == 0);

}

TEST_CASE("Date - Constructor errors") {

    REQUIRE_THROWS_AS(Date(32, 11, 2026), std::invalid_argument);
    REQUIRE_THROWS_AS(Date(31, 13, 2026), std::invalid_argument);
    REQUIRE_THROWS_AS(Date(0, 6, 2026), std::invalid_argument);
    REQUIRE_THROWS_AS(Date(1, 0, 2026), std::invalid_argument);

}