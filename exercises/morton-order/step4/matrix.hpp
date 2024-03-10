#ifndef MORTON_MATRIX_HPP
#define MORTON_MATRIX_HPP

#include <cassert>
#include <memory>
#include <iterator>
#include <type_traits>
#include "bits.hpp"

namespace morton {
  // Forward declare the iterator
  template <typename T>
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
  template <typename T>
  class matrix {
  public:
    using value_type = T;
    using iterator = matrix_iterator<value_type>;
    // TODO: using const_iterator = ?;

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
    matrix(uint32_t r) : _rank(r), _data(new value_type[r*r]) {
      // Check it's a power of 2. Could consider throwing an
      // exception, but these are not in the syllabus!
      assert((r & (r-1)) == 0);
    }

    // Create a new matrix with contents copied from this one
    matrix duplicate() const {
      matrix ans(_rank);
      std::copy(data(), data() + size(), ans.data());
      return ans;
    }

    // Get rank size
    uint32_t rank() const {
      return _rank;
    }

    // Get total size
    uint64_t size() const {
      return uint64_t(_rank) * uint64_t(_rank);
    }

    // Const element access
    const value_type& operator()(uint32_t i, uint32_t j) const {
      auto z = encode(i, j);
      return _data[z];
    }

    // Mutable element access
    value_type& operator()(uint32_t i, uint32_t j) {
      auto z = encode(i, j);
      return _data[z];
    }


    // Raw data access (const and mutable versions)
    const value_type* data() const {
      return _data.get();
    }
    value_type* data() {
      return _data.get();
    }

    // Mutable iterators
    iterator begin() {
      return iterator(data(), data());
    }
    iterator end() {
      return iterator(data(), data() + size());
    }

        // Mutable iterators
    const_iterator begin() const {
      return const_iterator(data(), data());
    }
    const_iterator end() const {
      return const_iterator(data(), data() + size());
    }

  };

  // Iterator type for matrices
  template <typename T>
  class matrix_iterator {
  public:
    // Here we exposed the member types required by the standard
    // library's concept of an iterator. See:
    // https://en.cppreference.com/w/cpp/iterator/iterator_traits
    // 
    // TODO: will these be OK if T is a constant type? (e.g. `int const`)
    using value_type = T;
    using difference_type = int64_t;
    using reference = T&;
    using pointer = T*;
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
    uint32_t x() const {
      auto z = _ptr - _start;
      return pack(z);
    }
    uint32_t y() const {
      auto z = _ptr - _start;
      return pack(z >> 1);
    }

    // Comparison operators.
    friend bool operator==(const matrix_iterator& a, const matrix_iterator& b) {
      return a._ptr == b._ptr;
    }
    friend bool operator!=(const matrix_iterator& a, const matrix_iterator& b) {
      return !(a == b);
    }

    // Dereference operator
    reference operator*() const {
      return *_ptr;
    }

    // Preincrement operator
    matrix_iterator& operator++() {
      ++_ptr;
      return *this;
    }
    // Predecrement operator
    matrix_iterator& operator--() {
      --_ptr;
      return *this;
    }

  private:
    // Private constructor
    matrix_iterator(pointer start, pointer current)
      : _start(start), _ptr(current) {
    }

    // Other constructors should probably not be publicly visible, so
    // we need to allow matrix access.
    // 
    // TODO: Suppose T = int const. How do get `int` from `int const`?
    //       See the standard type support library:
    //       https://en.cppreference.com/w/cpp/types
    friend matrix<T>;
  };
}

#endif
