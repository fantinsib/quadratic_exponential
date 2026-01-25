
#include <vector>
#include <optional>


struct Path{

    std::vector<float> spot_path;
    std::optional<std::vector<float> > volatilty;

    float end_value() {return spot_path.back();}
};


