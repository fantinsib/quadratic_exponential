/*
                       _                        _       
 _ __ ___   ___  _ __ | |_ ___    ___ __ _ _ __| | ___  
| '_ ` _ \ / _ \| '_ \| __/ _ \  / __/ _` | '__| |/ _ \ 
| | | | | | (_) | | | | ||  __/ | (_| (_| | |  | | (_) |
|_| |_| |_|\___/|_| |_|\__\___|  \___\__,_|_|  |_|\___/ 

*/

#include "engine.hpp"
#include "schemes/schemes.hpp"
#include <memory>
#include <optional>
#include "types/path.hpp"


/**
 * @brief Construct a new Monte Carlo engine
 *
 * @param scheme : a scheme instanciated with a model to simulate 
 * 
 */
class MonteCarlo : Engine 
{

public:
    explicit MonteCarlo(std::shared_ptr<Scheme> scheme) : 
        scheme_(std::move(scheme)) {}
    
    template <class SchemeT>
    explicit MonteCarlo(SchemeT scheme)
    : scheme_(std::make_shared<SchemeT>(std::move(scheme))) {}



    /**
     * @brief Simulates the scheme over a specified time interval
     * 
     * @param S0 the initial spot
     * @param n the number of steps 
     * @param T the time horizon
     * @param v0 optional initial volatility 
     * @return Path object
     */
    Path simulate(float S0, int n, float T, std::optional<float> v0 = std::nullopt);
    void set_seed(int s){seed_ = s;};
    int get_seed() {return seed_;}

    private:
    const std::shared_ptr<Scheme> scheme_; 

    size_t seed_;

};