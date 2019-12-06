// list/list.c
// 
// Implementation for linked list.
//
// <Swarnim>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { 
  list_t *l = (list_t*)malloc(sizeof(list_t)); 
  l -> head = NULL;
  return l; 
}

void list_free(list_t *l) {
  free(l);
}

void list_print(list_t *l) {
  if (l -> head != NULL) {
    node_t *head = l ->head;
    while (head->next != NULL){
      printf("%d->", head ->value);
      head = head -> next;
    }
    printf("%d", head->value);
  }
}

int list_length(list_t *l)
{ 
  if (l-> head == NULL) {
    return 0;
  }
  int count = 1;
  node_t *head = l ->head; 
  while (head-> next != NULL) 
  {
    count++;
    head = head-> next;
  }
  return count; 
}

void list_add_to_back(list_t *l, elem value)
{
  if (l-> head == NULL) {
    node_t * temp = (node_t*)malloc(sizeof(node_t)); 
    temp -> value = value;
    temp -> next = NULL;
    l -> head  = temp;
    return;
  }
  node_t* curr = l->head;
  while (curr->next != NULL) {
  curr = curr->next;
  }
  node_t * temp = (node_t*)malloc(sizeof(node_t)); 
  temp -> value = value;
  temp -> next = NULL;
  curr -> next = temp;
}

void list_add_to_front(list_t *l, elem value) {
  if (l-> head == NULL) {
    node_t * temp = (node_t*)malloc(sizeof(node_t)); 
    temp -> value = value;
    temp -> next = NULL;
    l -> head  = temp;
    return;
  }
  node_t* head = l->head;
  node_t * temp = (node_t*)malloc(sizeof(node_t)); 
  temp -> value = value;
  temp -> next = head;
  l -> head = temp;
}

void list_add_at_index(list_t *l, elem value, int index) 
{
  int length = list_length(l);
  if (index < 0) { //handling negative indices
    index = length + index ;
  }
  if (index == 0 || length == 0) {
    list_add_to_front(l, value);
    return;
  }
  if (index > length) {
    printf("Invalid Index");
    return;
  }
  node_t *curr = l -> head;
  int i = 0;
  while  (i < index) {
    curr = curr-> next;
    i++;
  }
  node_t * temp = (node_t*)malloc(sizeof(node_t)); 
  temp -> value = value;
  temp -> next = curr->next;
  curr -> next = temp;
}

elem list_remove_from_back(list_t *l) 
{ 
  if (l-> head == NULL) {
    printf("LIST EMPTY ERROR");
    return -1;
  }
  int length = list_length(l);
  if (length == 1) {
    node_t* head = l->head;
    int val = head->value;
    free(head);
    l->head = NULL;
    return val;
  }
  node_t* curr = l->head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  node_t* last = curr -> next;
  int val = last->value;
  curr-> next = NULL;
  free(last);
  return val;
}

 elem list_remove_from_front(list_t *l)
{
  if (l-> head == NULL) {
    printf("List is empty");
    return -1;
  }
  int length = list_length(l);
  if (length == 1) {
    node_t* head = l->head;
    int val = head->value;
    free(head);
    l->head = NULL;
    return val;
  }
  node_t* head = l -> head;
  node_t* next = head->next;
  int val = head->value;
  free(head);
  l->head = next;
  return val;
}

elem list_remove_at_index(list_t *l, int index) 
{ 
  if (l-> head == NULL) {
    printf("List is empty");
    return -1;
  }
  int length = list_length(l);
  if (index < 0) { 
    index = length + index;
  }
  if (length == 0) {
    return list_remove_from_front(l);
  }
  if (length == index+1) {
    return list_remove_from_back(l);
  }
  node_t* curr = l->head;
  int i= 1;
  while ( i < index) {
    curr = curr->next;
    i++;
  }
  node_t* toBeDeleted = curr -> next;
  int val = toBeDeleted->value;
  curr-> next = toBeDeleted->next;
  free(toBeDeleted);
  return val;
}

bool list_is_in(list_t *l, elem value) 
{ 
  if (l-> head == NULL) {
    printf("LIST EMPTY ERROR");
    return false;
  }
  node_t* curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}
elem list_get_elem_at(list_t *l, int index) 
{
  if (l-> head == NULL) {
    printf("LIST EMPTY ERROR");
    return -1;
  }
  int length = list_length(l);
  if (index < 0) { //handling negative indices
    index = length + index;
  }

  node_t* curr = l->head;
  int count = 0;
  while (curr != NULL) {
    if (count == index) {
      return curr->value;
    }
    count++;
    curr = curr->next;
  }
  return -1;
}
int list_get_index_of(list_t *l, elem value) 
{ 
   if (l-> head == NULL) {
    printf("List is empty");
    return -1;
  }
  node_t* curr = l->head;
  int count = 0;
  while (curr != NULL) {
    if (curr->value == value) {
      return count;
    }
    count++;
    curr = curr->next;
    
  }
  return -1;
}