#include "list.hpp"
#include <iostream>
#include <cassert>

list::node::node() : next(nullptr), prev(nullptr) {
}

list::data_t& list::node::get() {
  return value;
}
const list::data_t& list::node::get() const {
  return value;
}

// Default constructor - empty list
list::list() : head(nullptr), tail(nullptr) {
}

// Destructor
list::~list() {
  while(head) {
    pop_front();
  }
}

// Implement getting the front and back!


// Get the next/previous node in the list
list::node* list::node_next(node* n) {
  return n->next;
}
list::node* list::node_prev(node* n) {
  return n->prev;
}

// Add the data to a new node at the front of the list
list::node* list::push_front(const data_t& d) {
  return insert_before(head, d);
}

// Implement this member function
list::node* list::insert_before(node* will_be_next, const data_t& d) {
    std::cout << "Implement insert_before!" << std::endl;
    assert(false);
}

// Remove the first element from the list (if it exists)
void list::pop_front() {
  std::cout << "Implement pop_front - don't forget to release memory!" << std::endl;
  assert(false);
}
