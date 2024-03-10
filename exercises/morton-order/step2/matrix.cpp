#include "matrix.hpp"

#include <algorithm>

namespace morton {

  matrix::matrix(uint32_t r)
    : _rank(r), _data(new int[r*r]) 
  {
    // Check it's a power of 2. Could consider throwing an
    // exception, but these are not in the syllabus!
    assert((r & (r-1)) == 0);
  }

  // Create a new matrix with contents copied from this one
  matrix matrix::duplicate() const {
    matrix ans(_rank);
    std::copy(data(), data() + size(), ans.data());
    return ans;
  }

  // Get rank size
  uint32_t matrix::rank() const {
    return _rank;
  }

  // Get total size
  uint64_t matrix::size() const {
    return uint64_t(_rank) * uint64_t(_rank);
  }

  // Const element access
  const int& matrix::operator()(uint32_t i, uint32_t j) const {
    auto z = encode(i, j);
    return _data[z];
  }

  // Mutable element access
  int& matrix::operator()(uint32_t i, uint32_t j) {
    auto z = encode(i, j);
    return _data[z];
  }

  // Raw data access (const and mutable versions)
  const int* matrix::data() const {
    return _data.get();
  }
  int* matrix::data() {
    return _data.get();
  }

  // Mutable iterators
  // TODO: implement functions to get iterators to first and
  //       just-past-the-last elements in the matrix
  // NB: use trailing return type to have access to names defined
  // inside the class namespace.
  auto matrix::begin() -> iterator {
  }
  auto matrix::end() -> iterator {
  }

  // TODO: implement constructors.

  // TODO
  // Get the x/y coordinates of the current element
  uint32_t matrix_iterator::x() const {
  }
  uint32_t matrix_iterator::y() const {
  }

  // Dereference operator
  auto matrix_iterator::operator*() const -> reference {
    // TODO
  }

    // Preincrement operator
  matrix_iterator& matrix_iterator::operator++() {
    // TODO
  }
  // TODO
  // Predecrement operator
  matrix_iterator& matrix_iterator::operator--() {
    // TODO
  }
  // Comparison operators.
  bool operator==(const matrix_iterator& a, const matrix_iterator& b) {
    // TODO
  }
  // Note this can be done in terms of the above
  bool operator!=(const matrix_iterator& a, const matrix_iterator& b) {
    return !(a == b);
  }
}

