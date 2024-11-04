#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "history.h"
#include "tokenizer.h"


int main() {
  char input[100];
  List *history = init_history();  // Initialize the history list


  while (1) {
    printf("> ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
      // Remove newline character from input
      size_t len = strlen(input);
      if (len > 0 && input[len - 1] == '\n') {
	input[len - 1] = '\0';
      }


      // Check if the command is to retrieve a specific history entry

      if (input[0] == '!' && strlen(input) > 1) {
	int id = atoi(&input[1]);  // Convert the string following '!' to an integer
	char *entry = get_history(history, id);  // Retrieve the history entry by ID
	if (entry != NULL) {
	  printf("History %d: %s\n", id, entry);  // Print the retrieved history entry
	  //print the tokenization
	  char **tokens = tokenize(entry);
	  printf("tokens %d: %s",id,entry);
	  print_tokens(tokens);
	  free_tokens(tokens);
	} else {
	  printf("No history entry with ID %d\n", id);  // Entry not found
	}
      } else if (strcmp(input, "history") == 0) {
	// Command to view all history
	print_history(history);
      } else {
	// Add the input as a new history entry and confirm addition
	add_history(history, input);
	printf("Added to history: %s\n", input);
      }
    }
  }

  // Free the history list before exiting
  free_history(history);
  return 0;
}
