#include <string>
#include <fstream>
#include <algorithm>
#include "header.hpp"

void set_value(long long val)
{
    std::ofstream file{ std::string(actual_brightness_file) };

    if (file) {
        file << val;
    } else {
        std::exit(84);
    }
}

void set_percent(long double percent)
{
    set_value(std::min(percent, 100.L) / 100.L * get_max_value());
}

void increase_percent(long double percent)
{
    set_percent(get_percentage(get_current_value()) + percent);
}

void increase_value(long long value)
{
    set_value(std::min(get_current_value() + value, get_max_value()));
}
