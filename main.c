#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
 
  list_t *l = list_alloc();
  list_add_to_back(l, 231);
  list_add_to_back(l, 122);
  list_add_to_front(l, 41);
  list_add_at_index(l, 22, -1);
  list_print(l);
  printf("\n%d", list_remove_at_index(l, 2));
  //printf("\n%d", list_remove_from_front(l));
  printf("The list length is %d\n", list_length(l));
  list_print(l);
  bool x = list_is_in(l, 11);
  printf("%s", x?"true":"false"); 
  list_add_at_index(l, 67, -1);
  list_print(l);
  printf("The element at last index is %d\n", list_get_elem_at(l, -1));
  list_add_at_index(l, -21,-2);
  list_print(l);


}