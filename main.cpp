#include <set>
#include <array>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "util.hpp"
#include "header.hpp"

using namespace std::string_literals;

[[noreturn]] static void display_brightness()
{
    const long long value{ get_current_value() };

    std::cout << "The brightness is currently " << value << " (" << get_percentage(value) << "%)." << std::endl;
    std::exit(0);
}

[[noreturn]] void increase_percent_argv(char *arg)
{
    const long double percent{ check_arg<long double>(arg, "isn't a valid percentage !") };
    const long double requested{ add_percent(get_percentage(get_current_value()), percent) };
    const std::string warning{ 
        my_format<long long>("[Warning] Low brightness requested ({}% <= {}%), you may not see the screen, do you want to continue ? [Yy/Nn]\t", requested, MIN_PERCENT)
    };

    if (requested <= MIN_PERCENT && is_in(get_valid_input<char>(warning, "YyNn"s), "Nn"s)) {
        std::exit(21);
    }
    increase_percent(percent);
    std::exit(0);
}

[[noreturn]] void increase_value_argv(char *arg)
{
    const long long value{ check_arg<long long>(arg, "isn't a valid value !") };
    const long long requested{  add_value(get_current_value(), value) };
    const std::string warning{ 
        my_format<long long>("[Warning] Low brightness requested ({} <= {}), you may not see the screen, do you want to continue ? [Yy/Nn]\t", requested, MIN_VALUE)
    };

    if (requested <= MIN_VALUE && is_in(get_valid_input<char>(warning, "YyNn"s), "Nn"s)) {
        std::exit(21);
    }
    increase_value(value);
    std::exit(0);
}

[[noreturn]] void set_percent_argv(char *arg)
{
    const long double percent{ check_arg<long double>(arg, "isn't a valid percentage !") };
    const std::string warning{ 
        my_format<long long>("[Warning] Low brightness requested ({}% <= {}%), you may not see the screen, do you want to continue ? [Yy/Nn]\t", percent, MIN_PERCENT)
    };

    if (percent <= MIN_PERCENT && is_in(get_valid_input<char>(warning, "YyNn"s), "Nn"s)) {
        std::exit(21);
    }
    set_percent(percent);
    std::exit(0);
}

[[noreturn]] void set_value_argv(char *arg)
{
    const long long value{ check_arg<long long>(arg, "isn't a valid value !") };
    const std::string warning{ 
        my_format<long long>("[Warning] Low brightness requested ({} <= {}), you may not see the screen, do you want to continue ? [Yy/Nn]\t", value, MIN_VALUE)
    };

    if (value <= MIN_VALUE && is_in(get_valid_input<char>(warning, "YyNn"s), "Nn"s)) {
        std::exit(21);
    }
    set_value(value);
    std::exit(0);
}

[[noreturn]] void set_max_argv()
{
    set_percent(100.L);
    std::exit(0);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        display_brightness();
    } else if (argc == 2) {
        if (std::set{"-h"s, "--help"s}.contains(argv[1])) {
            help();
        } else if (argv[1] == "--max"s) {
            set_max_argv();
        }
        increase_percent_argv(argv[1]);
    } else if (argc == 3) {
        if (argv[1] == "--set"s) {
            set_percent_argv(argv[2]);
        } else if (argv[1] == "--value"s) {
            increase_value_argv(argv[2]);
        } else if (argv[1] == "--set-value"s) {
            set_value_argv(argv[2]);
        }
    }
    return 42;
}