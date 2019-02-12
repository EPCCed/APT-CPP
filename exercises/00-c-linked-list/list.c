#include "list.h"
#include <stdlib.h>

struct list {
};

struct node {
};

list* list_init() {
  list* ans = (list*)malloc(sizeof(list));

  return ans;
}

data_t list_data(node* n) {
}

// Get the front and back or NULL if empty
node* list_front(list* lst) {
}
node* list_back(list* lst)  {
}

// Get the next node in the list or NULL if there is none
node* list_node_next(node* n) {
}

// Get the previous node in the list or NULL if there is none
node* list_node_prev(node* n) {
}

// Add the data to a new node at the front of the list
node* list_push_front(list* lst, const data_t d) {




}

// Add the data to a new node at the end of the list
node* list_push_back(list* lst, const data_t d) {




}

// Add the data to a new node after this one
node* list_insert_after(list* lst, node* before, const data_t d) {





}

// Add the data to a new node before this one
node* list_insert_before(list* lst, node* after, const data_t d) {
  // argument will after the new node
  




}

// Remove the node from the list
void list_remove(list* lst, node* n) {



}

// Remove the front node
void list_pop_front(list* lst) {

}

// Remove the back node
void list_pop_back(list* lst) {

}

void list_delete(list* lst) {
}
