#pragma once

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <thread>

namespace VulkanEngine {
struct ProfileResult {
  std::string name;
  std::uint64_t start;
  std::uint64_t end;
  std::uint32_t threadID;
};

struct ProfileSession {
  ProfileSession(const std::string &session_name) : name(session_name) {}
  std::string name;
};

class Profiler {
public:
  Profiler() : currentSession(nullptr), profileCount(0), sessionIsEnd(false) {}
  virtual ~Profiler() {
    if (!sessionIsEnd) {
      endSession();
    }
  }
  void beginSession(const std::string &name);
  void endSession();

  void writeProfile(const ProfileResult &result);

  static Profiler &getInstance() {
    static Profiler instance;
    return instance;
  }

private:
  void writeHeader();
  void writeFooter();

  std::string return_current_time_and_date();

private:
  ProfileSession *currentSession;
  std::ofstream outputStream;
  std::int32_t profileCount;
  bool sessionIsEnd;
};

class ProfilerTimer {
public:
  ProfilerTimer(const std::string_view &name) : name(name), timerIsStop(false) {
    startTimepoint = std::chrono::high_resolution_clock::now();
  }

  virtual ~ProfilerTimer() {
    if (!timerIsStop) {
      stop();
    }
  }

  void stop();

private:
  const std::string_view name;
  std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
  bool timerIsStop;
};

} // namespace VulkanEngine

#define PROFILER
#ifdef PROFILER
#define PROFILE_SCORE(name) VulkanEngine::ProfilerTimer timer##__LINE__(name);
#ifdef _MSC_VER
#define PROFILE_FUNCTION() PROFILE_SCORE(__FUNCSIG__)
#else
#define PROFILE_FUNCTION() PROFILE_SCORE(__PRETTY_FUNCTION__)
#endif
#else
#define PROFILE_SCORE(name)
#define PROFILE_FUNCTION()
#endif
