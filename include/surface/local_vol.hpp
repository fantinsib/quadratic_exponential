#pragma once

#include <vector>

class LocalVolatilitySurface {

public:

    /**
     * @brief Makes a local volatility surface
     * 
     * @param times a vector of maturities
     * @param spots a vector of spot values
     * @param sigma a vector of local volatilities
     */
    LocalVolatilitySurface(std::vector<double> times,
                           std::vector<double> spots,
                           std::vector<double> sigma);


    /**
     * @brief Returns the local volatility 
     * sigma(t, S) interpolated from the grid.
     * 
     * @param t the time (in years)
     * @param S the spot price 
     * @return double : the interpolated local volatility at (S, t)
     *
     * @note the local volatility is obtained by bilinear interpolation.
     * If S or t fall outside the grid, value is clamped to the nearest
     * boundary 
     */
    double sigma(double t, double S) const;


private:

    std::vector<double> times_;
    std::vector<double> spots_;
    std::vector<double> loc_vol_; 

};