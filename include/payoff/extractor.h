#pragma once

#include <memory>
#include <span>

#include "observationschedule.h"
#include "types/simulationresult.hpp"

class Extractor {
    public:
        Extractor(std::shared_ptr<SimulationResult> res) : res_(res) {};
        std::vector<double> get(ObservationSchedule& schedule) const;

    private:
        std::shared_ptr<SimulationResult> res_;

        

};