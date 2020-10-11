#include "Engine.h"
#include "common/Log.h"

int main(int argc, const char *argv[]) {

  try {

    VulkanEngine::Engine engine(argc, argv);
    return engine.run();

  } catch (const std::exception &e) {
    ELOG("Exception: {0}", e.what())
    return -1;
  }
  return -234234234; // REALLY REALLY WRONG
}