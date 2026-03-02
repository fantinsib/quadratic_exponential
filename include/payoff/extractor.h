#pragma once

#include <memory>
#include <span>

#include "observationschedule.h"
#include "types/simulationresult.hpp"

class Extractor {
    public:

        /**
         * @brief Util to extract data from a simulation result
         * for payoff calculations 
         * 
         * @param res 
         */
        Extractor(std::shared_ptr<SimulationResult> res);

        /**
         * @brief Returns the vector of spot values at the time specified 
         * 
         * @param schedule an ObservationSchedule containing the dates of observation
         * @return std::vector<double> 
         */
        std::vector<double> get(ObservationSchedule& schedule) const;
        
        /**
         * @brief Converts the date from the observation schedule to index 
         * 
         * @return std::vector<size_t> 
         */
        std::vector<size_t> tf_to_index(std::vector<double> Ts) const; 

    private:
        std::shared_ptr<SimulationResult> res_;
        double T_;
        size_t n_steps_;
        size_t n_paths_;
        std::vector<double> timeframe_; 

        

};