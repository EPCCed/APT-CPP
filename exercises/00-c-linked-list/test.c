#include "test.h"

/* Count the number of elements in the list */
int list_size(list* lst) {
  int count = 0;
  for (node* n = list_front(lst); n; n = list_node_next(n)) 
    ++count;
  return count;
}
