#include <cassert>
#include <cstdlib>
#include <iostream>

#include "list.hpp"
#include "util.hpp"

// Exercise 1 - a linked list

// This program tests your list implementation by generating some
// random data and inserting it into a list, keeping it sorted.  It
// needs one command line argument, an integer, which is the number of
// elements to generate.  It will check they are indeed sorted and
// print the time it took.

// I have provided a header file (list.hpp) and a partical implemenation (list.cpp).

// Your task is to complete list.cpp such that this program runs!

int main(int argc, char** argv) {
  
  // Requires one argument, the size of the list to generate
  assert(argc == 2);
  int size = std::atoi(argv[1]);
  
  // We are going to fill this list with some random integers and keep
  // it sorted
  list sorted;

  // Measure the time
  Timer t;
  for (auto i = 0; i != size; ++i) {
    // Get a random in [0,1000]
    auto x = rand(1000);
    
    // find insertion point
    auto nd = sorted.front();
    while (nd && nd->get() < x) {
      nd = sorted.node_next(nd);
    }
    // insert
    sorted.insert_before(nd, x);
  }
  
  std::cout << "Time to insert " << size << " integers = " << t.GetSeconds() << " s" << std::endl;
  
  // Check they are ordered
  int last = 0;
  for(auto nd = sorted.front(); nd; nd = sorted.node_next(nd)) {
    assert(last <= nd->get());
    last = nd->get();
  }
  std::cout << "Were correctly ordered" << std::endl;
}
