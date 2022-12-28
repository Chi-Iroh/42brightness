#pragma once

#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

static constexpr long double MIN_PERCENT{ 0.5L };
#define MIN_VALUE (MIN_PERCENT / 100.L * get_max_value())

template<typename T>
T check_arg(char *str, const std::string msg = "")
{
    try {
        return static_cast<T>(std::stold(str));
    } catch(std::invalid_argument& error) {
        if (!msg.empty()) {
            std::cerr << str << ' ' << msg << std::endl;
        }
        std::exit(42);
    }
}

template<typename T, typename Container>
bool is_in(T val, Container container)
{
    for (auto elem : container) {
        if (val == elem) {
            return true;
        }
    }
    return false;
}

template<typename T, typename Container>
T get_valid_input(const std::string& text, Container valid)
{
    T val{};

    while (true) {
        std::cout << text;
        if (!(std::cin >> val)) {
            std::cin.ignore();
            std::cin.clear();
            continue;
        }
        if (is_in(val, valid)) {
            break;
        }
    }
    return val;
}

template<typename T>
requires(std::is_arithmetic_v<T>)
std::string float_without_trailing_zeros(T val)
{
    std::string str{ (std::ostringstream{} << val).str() };

    while (str.find('.') != std::string::npos && str.back() == '0') {
        str.pop_back();
    }
    return str;
}

template<typename T>
static std::string my_format(std::string str, T val, T min)
{
    const std::array<T*, 2> elems{ &val, &min };

    for (std::size_t i = 0; i < 2; i++) {
        std::size_t curly_brackets_pos{ str.find("{}") };
        if (curly_brackets_pos == std::string::npos) {
            return str;
        }
        str.erase(str.begin() + curly_brackets_pos, str.begin() + curly_brackets_pos + 2);
        str.insert(curly_brackets_pos, float_without_trailing_zeros<T>(*elems[i]));
    }
    return str;
}
