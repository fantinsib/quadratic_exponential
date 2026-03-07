#pragma once

#include <stdexcept>
#include <vector>





class ObservationSchedule {
    public:
        /**
         * @brief Define a set of maturities in year at which to observe the spot value
         * 
         * @param Ts a std::vector<double> representing the maturities (in years)
         */
        ObservationSchedule(std::vector<double>& Ts) : Ts_(std::move(Ts)) 
        {
            n_obs = Ts_.size();
        };

        const std::vector<double>& get_Ts() const {return Ts_;}
        size_t get_n_obs() const {return n_obs;}
    private:
        std::vector<double> Ts_;
        size_t n_obs;

};