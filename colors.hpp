#pragma once
#include <string_view>

namespace color {
    constexpr std::string_view red = "0;31";
    constexpr std::string_view green = "0;32";
    constexpr std::string_view orange = "0;33";
    constexpr std::string_view blue = "0;34";
    constexpr std::string_view purple = "0;35";
    constexpr std::string_view cyan = "0;36";
    constexpr std::string_view yellow = "1;33";
    constexpr std::string_view white = "1;37";

    constexpr std::string_view none = "\033[0m";

    namespace light {
        constexpr std::string_view gray = "0;37";
        constexpr std::string_view red = "1;31";
        constexpr std::string_view green = "1;32";
        constexpr std::string_view blue = "1;34";
    };

    namespace dark {
        constexpr std::string_view gray = "1;30";
    };
};