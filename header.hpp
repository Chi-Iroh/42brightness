#pragma once
#include <utility>
#include <string_view>

static constexpr std::string_view actual_brightness_file{ "/sys/class/backlight/intel_backlight/brightness" };
static constexpr std::string_view max_brightness_file{ "/sys/class/backlight/intel_backlight/max_brightness" };

long long get_max_value();
long double get_percentage(long long brightness);
long long get_current_value();

void set_value(long long val);
void set_percent(long double percent);
void increase_percent(long double percent);
void increase_value(long long value);

long long add_value(long long value, long long n);
long double add_percent(long double percent, long double n);

[[noreturn]] void help();