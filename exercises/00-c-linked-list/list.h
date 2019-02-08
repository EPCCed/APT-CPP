#ifndef LIST_H
#define LIST_H

// Data to be stored in the list
typedef int data_t;

typedef struct list list;
typedef struct node node;

// Create an empty list
list* list_init();
void list_delete(list*);

// Get the front and back or NULL if empty
node* list_front(list*);
node* list_back(list*);

data_t* list_data(node*);

// Get the next node in the list or NULL if there is none
node* list_node_next(node*);
// Get the previous node in the list or NULL if there is none
node* list_node_prev(node*);

// Add the data to a new node at the front of the list
node* list_push_front(list*, const data_t);
// Add the data to a new node at the end of the list
node* list_push_back(list*, const data_t);
// Add the data to a new node after this one
node* list_insert_after(list*, node*, const data_t);
// Add the data to a new node before this one
node* list_insert_before(list*, node*, const data_t);

// Remove the front node
void list_pop_front(list*);
// Remove the back node
void list_pop_back(list*);

// Remove the pointed to node from the list
void list_remove(list*, node*);


#endif
