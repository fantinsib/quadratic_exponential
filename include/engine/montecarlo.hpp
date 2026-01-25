/*
                       _                        _       
 _ __ ___   ___  _ __ | |_ ___    ___ __ _ _ __| | ___  
| '_ ` _ \ / _ \| '_ \| __/ _ \  / __/ _` | '__| |/ _ \ 
| | | | | | (_) | | | | ||  __/ | (_| (_| | |  | | (_) |
|_| |_| |_|\___/|_| |_|\__\___|  \___\__,_|_|  |_|\___/ 

*/

#include "engine.hpp"
#include "schemes/schemes.hpp"
#include <optional>
#include "types/path.hpp"


/**
 * @brief Construct a new Monte Carlo engine
 * 
 */
class MonteCarlo : Engine 
{

    public:
    MonteCarlo(Scheme);

    Path simulate(float S0, int n, float T, std::optional<float> v0);

    private:





};