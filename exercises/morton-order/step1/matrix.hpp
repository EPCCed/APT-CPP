#ifndef MORTON_MATRIX_HPP
#define MORTON_MATRIX_HPP

#include <cassert>
#include "bits.hpp"

namespace morton {

  // 2D square matrix of ints that stores data in Morton order
  //
  // NB:
  // 
  //  - This simple implementation requires that the size be a power
  //    of 2 (or zero indicating an empty matrix)
  // 
  //  - The matrix does not need to be resizeable
  //
  //  - The matrix must not be implicitly copiable, must use explicit
  //    duplicate member function
  class matrix {
  private:
    // rank of matrix
    uint32_t _rank;
    // Data storage
    // TODO - choose how to store data and manage that memory

  public:
    // TODO - anything needed?
    matrix();

    // Construct with appropriate memory for an r by r matrix.
    matrix(uint32_t r);

    // Implicit copying is not allowed
    // TODO: do we need to do anything to prevent this?

    // Moving is allowed
    // TODO - will the default implementations be OK?
    matrix(matrix&& other) noexcept;
    matrix& operator=(matrix&& other) noexcept;

    // Destructor
    // TODO - will the default implemenation be OK?
    ~matrix();

    // Create a new matrix with contents copied from this one
    matrix duplicate() const;

    // Get rank size
    uint32_t rank() const;

    // Get total size
    uint64_t size() const;

    // Const element access
    const int& operator()(uint32_t i, uint32_t j) const;
    // Mutable element access
    int& operator()(uint32_t i, uint32_t j);

    // Raw data access (const and mutable versions)
    const int* data() const;
    int* data();
  };
}
#endif
