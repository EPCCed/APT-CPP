#ifndef LIST_HPP
#define LIST_HPP

// Simple linked list class
class list {
  
public:
  // Data to be stored in the list
  typedef int data_t;
  
  // A nested class for the list
  struct node {
    node();
    
    data_t& get();
    const data_t& get() const;
  private:
    friend list;
    node* prev;
    node* next;
    data_t value;
  };
  
  // Create an empty list
  list();
  ~list();
  
  // Get the front/back node or nullptr if empty
  node* front();
  node* back();

  // Get the next/previous node in the list or nullptr if there is none
  node* node_next(node*);
  node* node_prev(node*);
  
  // Add the data to a new node at the front/end of the list
  node* push_front(const data_t&);
  node* push_back(const data_t&);
  
  // Add the data to a new node after this one
  node* insert_after(node*, const data_t &);
  // Add the data to a new node before this one
  node* insert_before(node*, const data_t&);
  
  // Remove the front/back node
  void pop_front();
  void pop_back();
  
  // Remove the pointed to node from the list
  void remove(node*);
  
private:
  node* head;
  node* tail;
};
#endif
