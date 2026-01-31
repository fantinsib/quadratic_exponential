#include "types/date.hpp"

#include <optional>
#include <stdexcept>

Date::Date(int day, 
           int month, 
           int year, 
           std::optional<int> hour_, 
           std::optional<int> minute_,
           std::optional<int> second_) :

    D(day),
    M(month),
    Y(year), 
    h(hour_.value_or(0)), 
    m(minute_.value_or(0)), 
    s(second_.value_or(0))
    {
        if (M < 1 || M > 12) 
            throw std::invalid_argument("Date constructor : month value is not valid");
        if (D < 1 || D > 31) 
            throw std::invalid_argument("Date constructor : day value is not valid");
    }