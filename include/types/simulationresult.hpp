#pragma once 

#include "state.hpp"
#include "path.hpp"
#include "models/model.hpp"
#include "schemes/schemes.hpp"
#include <vector>


struct PathBundle {

    size_t n_paths;
    size_t n_steps;
    std::vector<float> spot;
    std::vector<float> var;

};

/**
 * @brief Structure containing a collection of Paths
 * 
 */
struct SimulationResult {

    size_t origin_seed;
    size_t n_paths;
    size_t n_steps;
    //Model model;
    //Scheme scheme;

    size_t get_npaths() {return n_paths;}
    size_t get_seed() {return origin_seed;}

    std::shared_ptr<PathBundle> paths;


};

