#pragma once

#include <vector>





class ObservationSchedule {
    public:
        ObservationSchedule(std::vector<double>& Ts) : Ts(std::move(Ts)) 
        {
            n_obs = Ts.size();
        };
        std::vector<double> Ts;
        size_t n_obs;
};