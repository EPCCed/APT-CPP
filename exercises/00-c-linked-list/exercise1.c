#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "test.h"
/*
 * Exercise 1
 * 
 * Implement in list.c the following:
 *  - list_init
 *  - list_push_front
 *  - list_front
 *  - list_node_next
 *  - list_delete
 * (As per the declarations in list.h)
 *
 * Test the executable by running it with a few integers as arguments,
 * e.g.:
 *
 * ./exercise1 5 4 1 28
 */
int main(int argc, char** argv) {
  assert(argc > 1);
  
  list* numbers = list_init();
  assert(list_size(numbers) == 0);
  printf("A list was created empty\n");

  // Start at 1 because 0 is the program name
  for (int i = 1; i != argc; ++i) {
    int val = atoi(argv[i]);
    node* old_front = list_front(numbers);

    list_push_front(numbers, val);
    assert(list_size(numbers) == i);
    printf("On list insertion a list got longer\n");

    assert(list_front(numbers) != old_front);
    printf("On list insertion the front changed\n");

    assert(list_data(list_front(numbers)) == val);
    printf("Retreiving the value gives what was added\n");
  }

  // count
  int count = list_size(numbers);
  assert(count == argc-1);
  printf("Successfully read %d integers\n", count);

  list_delete(numbers);
  printf("List was deleted\n");
}
