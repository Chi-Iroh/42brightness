#include <limits>
#include <algorithm>
#include "header.hpp"

long long add_value(long long value, long long n)
{
    const long long max_value{ get_max_value() };

    if (n > max_value) {
        n = max_value;
    } else if (n < 0) {
        n = 0;
    }
    return std::min(value + n, 100LL);
}

long double add_percent(long double percent, long double n)
{
    if (n > 100.L) {
        n = 100.L;
    } else if (n < 0.L) {
        n = 0.L;
    }
    return std::min(percent + n, 100.L);
}
