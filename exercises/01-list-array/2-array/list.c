#include "list.h"
#include <stdlib.h>

struct list {
  node* head;//_solution
  node* tail;//_solution
};

struct node {
  data_t value;//_solution
  node* prev;//_solution
  node* next;//_solution
};

list* list_init() {
  list* ans = (list*)malloc(sizeof(list));

  ans->head = NULL;//_solution
  ans->tail = NULL;//_solution
  return ans;
}

data_t list_data(node* n) {
  return n->value;//_solution
}

// Get the front and back or NULL if empty
node* list_front(list* lst) {
  return lst->head;//_solution
}
node* list_back(list* lst)  {
  return lst->tail;//_solution
}

// Get the next node in the list or NULL if there is none
node* list_node_next(node* n) {
  return n->next;//_solution
}

// Get the previous node in the list or NULL if there is none
node* list_node_prev(node* n) {
  return n->prev;//_solution
}

// Add the data to a new node at the front of the list
node* list_push_front(list* lst, const data_t d) {
  node* old_head = lst->head;//_solution

  // Create the new node//_solution
  node* new_head = (node*)malloc(sizeof(node));//_solution
  new_head->value = d;//_solution
  new_head->prev = NULL;//_solution
  new_head->next = old_head;//_solution

  // Add new node to front of list//_solution
  lst->head = new_head;//_solution

  // Set the ptr from old head or the list tail to new node//_solution
  if (old_head) {//_solution
    // there was a head node//_solution
    old_head->prev = new_head;//_solution
  } else {//_solution
    // was an empty list  - the new head is the only node//_solution
    lst->tail = new_head;//_solution
  }//_solution

  return new_head;//_solution
}

// Add the data to a new node at the end of the list
node* list_push_back(list* lst, const data_t d) {
  node* old_tail = lst->tail;//_solution

  // Create the new node//_solution
  node* new_tail = (node*)malloc(sizeof(node));//_solution
  new_tail->value = d;//_solution
  new_tail->next = NULL;//_solution
  new_tail->prev = old_tail;//_solution

  // Add new node to end of list//_solution
  lst->tail = new_tail;//_solution

  // Set the ptr from old tail or list front to new node//_solution
  if (old_tail) {//_solution
    // there was a tail node//_solution
    old_tail->next = new_tail;//_solution
  } else {//_solution
    // was an empty list  - the new tail is the only node//_solution
    lst->head = new_tail;//_solution
  }//_solution

  return new_tail;//_solution
}

// Add the data to a new node after this one
node* list_insert_after(list* lst, node* before, const data_t d) {
  // argument will before the new node//_solution

  // this one will be after//_solution
  node* after = before->next;//_solution

  // Set up the new node//_solution
  node* new_node = (node*)malloc(sizeof(node));//_solution
  new_node->value = d;//_solution
  new_node->prev = before;//_solution
  new_node->next = after;//_solution

  // Stitch new node into list//_solution
  if (after == NULL) {//_solution
    lst->tail = new_node;//_solution
  } else {//_solution
    after->prev = new_node;//_solution
  }//_solution

  before->next = new_node;//_solution

  return new_node;//_solution
}

// Add the data to a new node before this one
node* list_insert_before(list* lst, node* after, const data_t d) {
  // argument will after the new node
  
  // this one will be before//_solution
  node* before = after->prev;//_solution

  // Set up the new node//_solution
  node* new_node = (node*)malloc(sizeof(node));//_solution
  new_node->value = d;//_solution
  new_node->prev = before;//_solution
  new_node->next = after;//_solution

  // Stitch new node into list//_solution
  after->prev = new_node;//_solution

  if (before == NULL) {//_solution
    lst->head = new_node;//_solution
  } else {//_solution
    before->next = new_node;//_solution
  }//_solution

  return new_node;//_solution
}

// Remove the node from the list
void list_remove(list* lst, node* n) {
  node* before = n->prev;//_solution
  node* after = n->next;//_solution

  if (before == NULL) {//_solution
    lst->head = after;//_solution
  } else {//_solution
    before->next = after;//_solution
  }//_solution

  if (after == NULL) {//_solution
    lst->tail = before;//_solution
  } else {//_solution
    after->prev = before;//_solution
  }//_solution

  free(n);//_solution
}

// Remove the front node
void list_pop_front(list* lst) {
  node* head = lst->head;//_solution
  if (head != NULL) {//_solution
    lst->head = head->next;//_solution

    if (lst->head == NULL) {//_solution
      lst->tail = NULL;//_solution
    } else {//_solution
      lst->head->prev = NULL;//_solution
    }//_solution
    free(head);//_solution
  }//_solution
  // else already done//_solution
}

// Remove the back node
void list_pop_back(list* lst) {
  node* tail = lst->tail;//_solution
  if (tail != NULL) {//_solution
    lst->tail = tail->prev;//_solution

    if (lst->tail == NULL) {//_solution
      lst->head = NULL;//_solution
    } else {//_solution
      lst->tail->next = NULL;//_solution
    }//_solution
    free(tail);//_solution
  }//_solution
  // else already done//_solution
}

void list_delete(list* lst) {
  while (lst->head) {//_solution
    list_pop_front(lst);//_solution
  }//_solution
  free(lst);//_solution
}
