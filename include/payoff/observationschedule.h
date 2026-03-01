#pragma once

#include <vector>





class ObservationSchedule {
    public:
        ObservationSchedule(std::vector<size_t>& time_index) : time_index(std::move(time_index)) 
        {
            n_obs = time_index.size();
        };
        std::vector<size_t> time_index;
        size_t n_obs;
};