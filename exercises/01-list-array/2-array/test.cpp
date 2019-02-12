#include <cassert>
#include <iostream>
#include <cstdlib>

#include "Array.hpp"
#include "util.hpp"

// Exercise 2.1 - array

// This program tests your array implementation by generating some
// random data and inserting it into a list, keeping it sorted.  It
// needs one command line argument, an integer, which is the number of
// elements to generate.  It will check they are indeed sorted and
// print the time it took.

// I have provided a header file (Array.hpp) with a partial implemenation


int main(int argc, char** argv) {
  
  // Requires one argument, the size of the list to generate
  assert(argc == 2);
  int size = std::atoi(argv[1]);
  
  // We are going to fill this list with some random integers
  Array<int> data(size);
  
  // Measure the time
  Timer t;
  for (unsigned i = 0; i != size; ++i) {
    // Get a random in [0,1000]
    auto x = rand(1000);
    
    // find insertion point
    unsigned j;
    for(j = 0; j != i; ++j) {
      if (data[j] >= x)
	break;
    }
    
    // insert
    
    // First, shift all elements [j, i) up one (starting at the back
    // to avoid overwriting
    for (unsigned k = i; k != j; --k) {
      data[k] = data[k-1];
    }
    
    // Add the new value
    data[j] = x;
  }
  
  std::cout << "Time to store " << size << " integers = " << t.GetSeconds() << " s" << std::endl;
  
  // Check they are ordered
  // Note starting from 1 and less-than to avoid len(data)==0 bug
  for(unsigned i = 1; i < data.size(); ++i) {
    assert(data[i-1] <= data[i]);
  }
  std::cout << "Were correctly ordered" << std::endl;

  return 0;
}
