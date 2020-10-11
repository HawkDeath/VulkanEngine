#include "Profiler.h"

#pragma warning(disable : 4996)

namespace VulkanEngine {

void Profiler::beginSession(const std::string &name) {
  const std::string &filepath =
      "profiler_" + name + "_" + return_current_time_and_date() + ".json";
  outputStream.open(filepath);
  writeHeader();
  currentSession = new ProfileSession(name);
  sessionIsEnd = false;
}

void Profiler::endSession() {
  writeFooter();
  outputStream.close();
  delete currentSession;
  currentSession = nullptr;
  profileCount = 0;
  sessionIsEnd = true;
}

void Profiler::writeProfile(const ProfileResult &result) {
  if (profileCount++ > 0) {
    outputStream << ",";
  }

  std::string name = result.name;
  std::replace(name.begin(), name.end(), '"', '\'');

  outputStream << "{";
  outputStream << "\"cat\":\"function\",";
  outputStream << "\"dur\":" << (result.end - result.start) << ',';
  outputStream << "\"name\":\"" << name << "\",";
  outputStream << "\"ph\":\"X\",";
  outputStream << "\"pid\":0,";
  outputStream << "\"tid\":" << result.threadID << ",";
  outputStream << "\"ts\":" << result.start;
  outputStream << "}";

  outputStream.flush();
}

void Profiler::writeHeader() {
  outputStream << "{\"otherData\": {},\"traceEvents\":[";
  outputStream.flush();
}

void Profiler::writeFooter() {
  outputStream << "]}";
  outputStream.flush();
}

std::string Profiler::return_current_time_and_date() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y_%m_%d_%H_%M_%S");
  return ss.str();
}

void ProfilerTimer::stop() {
  auto endTimepoint = std::chrono::high_resolution_clock::now();

  std::uint64_t start =
      std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint)
          .time_since_epoch()
          .count();
  std::uint64_t end =
      std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint)
          .time_since_epoch()
          .count();

  std::uint32_t threadID = static_cast<std::uint32_t>(
      std::hash<std::thread::id>{}(std::this_thread::get_id()));

  Profiler::getInstance().writeProfile({name.data(), start, end, threadID});

  timerIsStop = true;
}
} // namespace VulkanEngine