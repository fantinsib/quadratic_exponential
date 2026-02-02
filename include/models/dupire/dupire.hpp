#pragma once



#include "surface/local_vol.hpp"
#include "models/model.hpp"

#include <memory>

struct Dupire : Model {

public:
    /**
     * @brief Constructs a Dupire model
     * 
     * @param r the risk-free rate
     * @param q the dividend yield
     * @param loc_vol_surface the local volatility surface of the model
     */
    Dupire(float r, float q, 
           std::shared_ptr<LocalVolatilitySurface> loc_vol_surface);


private:
    float r_; 
    float q_;

    std::shared_ptr<LocalVolatilitySurface> lv_surface_;

    
};