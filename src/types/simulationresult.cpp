#include "types/simulationresult.hpp"
#include <memory>
#include <stdexcept>




SimulationResult::SimulationResult(std::shared_ptr<std::vector<double>> paths, size_t seed,
                   size_t n_steps, size_t n_paths, double T, std::optional<std::shared_ptr<std::vector<double>>> v_paths):
                    paths_(std::move(paths)),
                    origin_seed_(seed),
                    n_paths_(n_paths), 
                    n_steps_(n_steps),
                    T_(T)
                    
                   
    {
        size_t paths_size = paths_->size();
        if (n_paths_*(n_steps_+1) != paths_size) throw std::invalid_argument("SimulationResult constructor : dimension of path vector does not match specified dimensions") ;

        if (T<=0) throw std::invalid_argument("SimulationResult constructor : time horizon must be greater than zero");

        if (v_paths.has_value()){
            if (v_paths.value()->size() != paths_size) throw std::logic_error("SimulationResult constructor : dimension of volatility vector does not match spot vector dimension");
            vols_ = std::move(v_paths.value());
        }
    }

double SimulationResult::avg_terminal_value(){
    double total_count = 0;
    for (size_t p = 0; p < n_paths_; p++){
        size_t add_idx = p*(n_steps_+1) + (n_steps_);
        double add = (*paths_)[add_idx];
        total_count += add;
    }
    return total_count/static_cast<double>(n_paths_);
}

std::vector<double> SimulationResult::get_spot_at(size_t t){

    if (t > n_steps_) throw std::invalid_argument("SimulationResult::get_spot_at : t cannot be larger than the number of steps");
    std::vector<double> spots_at_t(n_paths_);
    
    for (size_t i = 0; i < n_paths_; i++){

        spots_at_t[i] = (*paths_)[i*n_steps_ + t + i];
    }
    return spots_at_t;

}