#include "darts.h"

#include <cmath>
#include <utility>

namespace darts {
    constexpr double OUTSIDE_R{10.0};
    constexpr int OUTSIDE_S{0};
    constexpr double OUTER_R{5.0};
    constexpr int OUTER_S{1};
    constexpr double MIDDLE_R{1.0};
    constexpr int MIDDLE_S{5};
    constexpr int CENTER_S{10};
    constexpr std::pair<double, double> center{0, 0};

    int score(double x, double y) {
        double land = std::sqrt(std::pow(x - center.first, 2)
                + std::pow(y - center.second, 2));

        if (land > OUTSIDE_R)
            return 0;
        if (land > OUTER_R)
            return OUTER_S;
        if (land > MIDDLE_R)
            return MIDDLE_S;
        return CENTER_S;
    }

} // namespace darts
