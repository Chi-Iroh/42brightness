#include <array>
#include <string>
#include <cstdlib>
#include <iostream>
#include "colors.hpp"

static void display_name()
{
    using namespace std::string_literals;

    static constexpr std::array colors {
        color::blue,
        color::cyan,
        color::dark::gray,
        color::green,
        color::light::blue,
        color::light::gray,
        color::light::green,
        color::light::red,
        color::orange,
        color::purple,
        color::red,
        color::white,
        color::yellow
    };

    for (long long i = 0; char c : "42brightness") {
        std::string char_cmd = "\033[" + std::string(colors[i++]) + "m" + c;
        std::cout <<  std::string(char_cmd);
    }
    std::cout << std::string(color::none) << std::endl;
}

[[noreturn]] void help()
{
    display_name();
    std::cout << "Script to manage screen brightness" << std::endl;
    std::cout << "Options :" << std::endl;
    std::cout << "42brightness -h / --help : displays this text" << std::endl;
    std::cout << "42brightness <N> : (in/de)creases brightness of <N> percents" << std::endl;
    std::cout << "42brightness --value <N> : (in/de)creases brightness of <N>" << std::endl;
    std::cout << "42brightness --max : sets the max brightness (same as 42brightness --set 100)" << std::endl;
    std::cout << "42brightness --set <N> : sets brightness to <N>%" << std::endl;
    std::cout << "42brightness --set-value <N> : sets brightness to <N>" << std::endl;
    std::cout << "Be careful to not set too small values !" << std::endl;
    std::cout << "Returns codes :" << std::endl;
    std::cout << "\t- 0 : OK" << std::endl;
    std::cout << "\t- 21 : operation aborted (when low brightness asked and user is warned and cancels)" << std::endl;
    std::cout << "\t- 42 : bad argument(s)" << std::endl;
    std::cout << "\t- 84 : cannot open system files (program must run as root)" << std::endl;
    std::exit(0);
}