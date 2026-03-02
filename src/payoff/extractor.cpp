#include "payoff/extractor.h"
#include "payoff/observationschedule.h"
#include "types/simulationresult.hpp"
#include <memory>



Extractor::Extractor(std::shared_ptr<SimulationResult> res) :
    
    res_(res),
    T_(res->get_T()),
    n_steps_(res->get_nsteps()),
    n_paths_(res->get_npaths())  
{
    double dt = T_/n_steps_;
    std::vector<double> timeframe(n_steps_);
    
    for (size_t t =0; t < n_steps_; t++ ) {
        timeframe[t] = dt * t;
    }

    timeframe_ = timeframe;
}


std::vector<double> Extractor::get(ObservationSchedule& schedule) const {

    size_t n_spots = schedule.n_obs;
    
    for (size_t i = 0; i < n_spots; i++) {
        

    };

}

std::vector<size_t> Extractor::tf_to_index() const {

    
}

