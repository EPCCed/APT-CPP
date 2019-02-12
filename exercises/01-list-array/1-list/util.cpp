#include "util.hpp"
#include <random>

// This generates random ints in [0, max]
int rand(int max) {
  // For all the details, see:
  // http://en.cppreference.com/w/cpp/numeric/random
  static std::random_device rd;
  static std::mt19937 engine(rd());
  static std::uniform_int_distribution<int> dist(0,max);
  
  return dist(engine);
}

Timer::Timer() : t0(clock::now()) {
}
  
float Timer::GetSeconds() {
  std::chrono::duration<float> delta_t(clock::now() - t0);
  return delta_t.count();
}
