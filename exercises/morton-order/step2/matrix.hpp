#ifndef MORTON_MATRIX_HPP
#define MORTON_MATRIX_HPP

#include <cassert>
#include <memory>
#include <iterator>
#include "bits.hpp"

namespace morton {
  // Forward declare the iterator
  class matrix_iterator;

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
  public:
    using iterator = matrix_iterator;

  private:
    // rank of matrix
    uint32_t _rank;
    // Data storage
    // Note using array version of unique_ptr
    std::unique_ptr<int[]> _data;

  public:
    // Default initialisation of unique_ptr is OK
    matrix() = default;

    // Construct with appropriate memory for an r by r matrix.
    matrix(uint32_t r);

    // Implicit copying is not allowed
    // Use of unique_ptr prevents copying.

    // Moving is allowed
    // Default is ok because of choice to use unique_ptr to manage data storage

    // Destructor
    // Default ok because of unique_ptr

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

    // Mutable iterators to beginning and just-past-the-end
    iterator begin();
    iterator end();
  };

  // Iterator type for matrices
  class matrix_iterator {
  public:
    // Here we exposed the member types required by the standard
    // library's concept of an iterator. See:
    // https://en.cppreference.com/w/cpp/iterator/iterator_traits
    using value_type = int;
    using difference_type = int64_t;
    using reference = int&;
    using pointer = int*;
    // This means we can go forwards and backwards.
    // Upgrading to a random access iterator would be eay but require
    // quite a lot of additional operations.
    using iterator_category = std::bidirectional_iterator_tag;

  private:
    // What members are required?

  public:
    // Default constructor
    // TODO: is this needed?
    matrix_iterator();

    // Note: must provide copy c'tor, copy assign
    // TODO: Decide if the default copy/move/destruct behaviour is
    //       going to be OK.

    // Get the x/y coordinates of the current element
    uint32_t x() const;
    uint32_t y() const;

    // Comparison operators. Note these are inline non-member friend
    // functions.
    friend bool operator==(const matrix_iterator& a, const matrix_iterator& b);
    // Note this can be done in terms of the above
    friend bool operator!=(const matrix_iterator& a, const matrix_iterator& b);

    // Dereference operator
    reference operator*() const;

    // Preincrement operator
    matrix_iterator& operator++();
    // Predecrement operator
    matrix_iterator& operator--();

  private:
    // TODO: declare and define appropriate constructor(s) to create
    //       iterators pointing into a matrix's data.
    // matrix_iterator(...);

    // Other constructors should probably not be publicly visible, so
    // we need to allow matrix access.
    friend matrix;
  };

}
#endif
