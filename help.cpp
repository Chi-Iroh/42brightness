#include <array>
#include <string>
#include <cstdlib>
#include <iostream>

[[noreturn]] void help()
{
    std::cout << "42brightness" << std::endl;
    std::cout << "Script to manage screen brightness" << std::endl;
    std::cout << "Options :" << std::endl;
    std::cout << "42brightness : displays current brightness" << std::endl;
    std::cout << "42brightness --format : displays current brightness (<value> <percentage> <max value>),";
    std::cout << " so that it's easier to be used by another program" << std::endl;
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