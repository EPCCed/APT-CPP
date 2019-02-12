#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array {
public:
  // C'tor - contains no data
  Array() : _size(0), _data(nullptr) {
    // Nothing else to do
  }
  // C'tor - has the space for n elements
  Array(unsigned n);
  // Copy c'tor - the new Array will have the same data as the input
  Array(const Array& other);
  // Move c'tor - the new Array will steal the data from the input
  Array(Array&& other);
  // D'tor - releases contained resources
  ~Array();

  // Copy assignment - frees any current resources and then copies
  // from input
  Array& operator=(const Array& other);
  // Move assignment - frees any current resources and steals data
  // from the input
  Array& operator=(Array&& other);

  // Return the number of elements in the Array
  unsigned size() const {
    return _size;
  }

  // Const element access
  const T& operator[](unsigned i) const;
  // Mutable element access
  T& operator[](unsigned i);

private:
  unsigned _size;
  T* _data;
};

// C'tor
template<class T>
Array<T>::Array(unsigned n) : _size(n) {
  _data = new T[n];
}

// Copy c'tor
template<class T>
Array<T>::Array(const Array& other) {
}

// Move c'tor
template<class T>
Array<T>::Array(Array&& other) : Array() {
}

// D'tor
template<class T>
Array<T>::~Array() {
  delete[] _data;
}

// Copy assignment
template<class T>
auto Array<T>::operator=(const Array& other) -> Array& {
}

// Move assignment
template<class T>
auto Array<T>::operator=(Array&& other) -> Array& {
}

// Const element access
template<class T>
const T& Array<T>::operator[](unsigned i) const {
  return _data[i];
}

// Non-const element access
template<class T>
T& Array<T>::operator[](unsigned i) {
  return _data[i];
}

#endif
