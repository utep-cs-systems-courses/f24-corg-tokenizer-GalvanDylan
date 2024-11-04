#include <stdlib.h>
#include <string.h>
#include "history.h"
#include <stdio.h>


List* init_history() {

  List *list = malloc(sizeof(List));

  if (list != NULL) {

    list->root = NULL;

  }

  return list;

}



// Helper function to create a copy of the input string

char* copy_string(const char *str) {

  char *copy = malloc(strlen(str) + 1);

  if (copy) {

    strcpy(copy, str);

  }

  return copy;

}



void add_history(List *list, char *str) {

  static int current_id = 1; // Keeps track of the current ID for each entry

  Item *new_item = malloc(sizeof(Item));

  if (new_item == NULL) return;  // Check for memory allocation failure



  new_item->id = current_id++;

  new_item->str = copy_string(str);  // Copy the input string to avoid memory issues

  new_item->next = NULL;



  // Add to the end of the list

  if (list->root == NULL) {

    list->root = new_item;

  } else {

    Item *temp = list->root;

    while (temp->next != NULL) {

      temp = temp->next;

    }

    temp->next = new_item;

  }

}

char* get_history(List *list, int id) {

Item *temp = list->root;

while (temp != NULL) {

if (temp->id == id) {

return temp->str; // Return the string if the ID matches

}

temp = temp->next;

}

return NULL;  // Return NULL if the ID is not found

}


void print_history(List *list) {

Item *temp = list->root;

while (temp != NULL) {

printf("%d: %s\n", temp->id, temp->str);

temp = temp->next;

}

}

void free_history(List *list) {

  Item *temp = list->root;

  while (temp != NULL) {

    Item *next = temp->next;

    free(temp->str);  // Free the string associated with each item

    free(temp);        // Free the item itself

    temp = next;

  }

  free(list);  // Free the history list

}

