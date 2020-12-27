#pragma once
#if ((WIN32_ || WIN32) && (_MSC_VER > 1200))
#pragma warning(disable : 4996)
#endif

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace VulkanEngine {
std::string current_time_and_date();
} // namespace VulkanEngine