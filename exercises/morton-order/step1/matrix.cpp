#include "matrix.hpp"

#include <algorithm>

namespace morton {

  // TODO - allocate some memory
  matrix::matrix(uint32_t r)
  {
    // Check it's a power of 2. Could consider throwing an
    // exception, but these are not in the syllabus!
    assert((r & (r-1)) == 0);
  }

  // Moving is allowed
  // TODO - if you need to provide these, do so here
  matrix::matrix(matrix&& other) noexcept {}
  matrix& matrix::operator=(matrix&& other) noexcept {}

  // Destructor
  // TODO - will the default implemenation be OK?
  matrix::~matrix() {}

  // Create a new matrix with contents copied from this one
  matrix matrix::duplicate() const {
    // TODO
  }

  // Get rank size
  uint32_t matrix::rank() const {
    return _rank;
  }

  // Get total size
  uint64_t matrix::size() const {
    return uint64_t(_rank) * uint64_t(_rank);
  }

  // TODO
  // Const element access
  const int& matrix::operator()(uint32_t i, uint32_t j) const {
  }

  // TODO
  // Mutable element access
  int& matrix::operator()(uint32_t i, uint32_t j) {
  }

  // TODO
  // Raw data access (const and mutable versions)
  const int* matrix::data() const {
  }
  int* matrix::data() {
}

