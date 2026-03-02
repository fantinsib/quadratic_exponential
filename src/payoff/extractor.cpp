#include "payoff/extractor.h"
#include "payoff/observationschedule.h"
#include "types/simulationresult.hpp"
#include <algorithm>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <vector>



Extractor::Extractor(std::shared_ptr<SimulationResult> res) :
    
    res_(res),
    T_(res->get_T()),
    n_steps_(res->get_nsteps()),
    n_paths_(res->get_npaths())  
{
    double dt = T_/static_cast<double>(n_steps_);
    std::vector<double> timeframe(n_steps_ +1);
    
    for (size_t t =0; t <= n_steps_ +1; t++ ) {
        timeframe[t] = dt * t;
    }

    timeframe_ = timeframe;
}


std::vector<double> Extractor::get(ObservationSchedule& schedule) const {

    size_t n_spots = schedule.n_obs;

    std::vector<size_t> idx = tf_to_index(schedule.Ts);
    
    for (size_t i = 0; i < n_spots; i++) {
        
        

    };

}

std::vector<size_t> Extractor::tf_to_index(std::vector<double> Ts) const {
    
    std::sort(Ts.begin(), Ts.end());
    if (Ts.back() > timeframe_.back()) throw std::invalid_argument("Extractor::tf_to_index : observation cannot be at a later date than maturity");
    std::vector<size_t> idx;
    idx.reserve(Ts.size());

    for (double t : Ts) {
        auto it = std::lower_bound(timeframe_.begin(), timeframe_.end(), t);
        idx.push_back(std::distance(timeframe_.begin(), it));
        
    };
    return idx;

}

