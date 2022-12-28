#include <fstream>
#include <exception>
#include <stdexcept>
#include "header.hpp"

long long get_max_value()
{
    std::ifstream file{ std::string(max_brightness_file) };
    long long max{};

    if (file) {
        file >> max;
        return max;
    }
    std::exit(84);
}

long double get_percentage(long long brightness)
{
    return static_cast<long double>(brightness) / get_max_value() * 100.L;
}

long long get_current_value()
{
    std::ifstream file{ std::string(actual_brightness_file) };
    long long brightness{};

    if (file) {
        file >> brightness;
        return brightness;
    }
    std::exit(84);
}