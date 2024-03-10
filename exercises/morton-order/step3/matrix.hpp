#ifndef MORTON_MATRIX_HPP
#define MORTON_MATRIX_HPP

#include <cassert>
#include <memory>
#include <iterator>
#include "bits.hpp"

namespace morton {
  // Forward declare the iterator
  // TODO: any changes?
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
  // TODO: convert to a template class
  class matrix {
  public:
    //TODO: it is common practice to make a type alias to the element
    //      type under the name `value_type`.
    //TODO: any changes?
    using iterator = matrix_iterator;

  private:
    // rank of matrix
    uint32_t _rank;
    // Data storage
    // Note using array version of unique_ptr
    std::unique_ptr<value_type[]> _data;

  public:
    // Default initialisation of unique_ptr is OK
    matrix() = default;

    // Construct with appropriate memory for an r by r matrix.
    matrix(uint32_t r);

    // Create a new matrix with contents copied from this one
    matrix duplicate() const;
    }

    // Get rank size
    uint32_t rank() const;

    // Get total size
    uint64_t size() const;

    // Const element access
    const value_type& operator()(uint32_t i, uint32_t j) const;

    // Mutable element access
    value_type& operator()(uint32_t i, uint32_t j);


    // Raw data access (const and mutable versions)
    const value_type* data() const;
    value_type* data();

    // Mutable iterators
    iterator begin();
    iterator end();
  };

  // Iterator type for matrices
  template <typename T>
  class matrix_iterator {
  public:
    // Here we exposed the member types required by the standard
    // library's concept of an iterator. See:
    // https://en.cppreference.com/w/cpp/iterator/iterator_traits
    // TODO: update for template case
    using value_type = int;
    using difference_type = int64_t;
    using reference = int&;
    using pointer = int*;
    // This means we can go forwards and backwards.
    // Upgrading to a random access iterator would be eay but require
    // quite a lot of additional operations.
    using iterator_category = std::bidirectional_iterator_tag;
    
  private:
    // We need the pointer to the first element to work out where we
    // are in the matrix for x/y calculation.
    pointer _start = nullptr;
    pointer _ptr = nullptr;

  public:
    // Default constructor
    matrix_iterator() = default;

    // Note: must provide copy c'tor, copy assign
    // Defaults are fine because this does not own data

    // Get the x/y coordinates of the current element
    uint32_t x() const;
    uint32_t y() const;

    // Comparison operators.
    friend bool operator==(const matrix_iterator& a, const matrix_iterator& b);
    friend bool operator!=(const matrix_iterator& a, const matrix_iterator& b);

    // Dereference operator
    reference operator*() const;

    // Preincrement operator
    matrix_iterator& operator++();
    // Predecrement operator
    matrix_iterator& operator--();

  private:
    // Private constructor
    matrix_iterator(pointer start, pointer current);

    // Other constructors should probably not be publicly visible, so
    // we need to allow matrix access.
    friend matrix<T>;
  };
}

#endif
