#ifndef UTIL_HPP
#define UTIL_HPP

#include <limits>
#include <chrono>

// This generates random ints in [0, max]
// If you omit max, then the upper limit is INT_MAX

int rand(int max = std::numeric_limits<int>::max());

// Very simple timer class
class Timer {
public:
  Timer();
  // Returns time since construction
  float GetSeconds();
    
private:
  typedef std::chrono::high_resolution_clock clock;  
  clock::time_point t0;
};

#endif
