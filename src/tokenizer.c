#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>///
// Implementation of space_char
int space_char(char c) {
  return (c == ' ' || c == '\t');
}

// Implementation of non_space_char
int non_space_char(char c) {
  return !space_char(c);
}

// Implementation of token_start
char *token_start(char *s) {
  while (*s != '\0' && space_char(*s)) {
    s++;
  }
  return (*s == '\0') ? NULL : s;
}

// Implementation of token_terminator
char *token_terminator(char *token) {
  while (*token != '\0' && !space_char(*token)) {
    token++;
  }
  return token;
}

// Implementation of count_tokens
int count_tokens(char *s) {
  int count = 0;
  char *current = token_start(s);
  while (current != NULL) {
    count++;
    current = token_start(token_terminator(current));
  }
  return count;
}

// Implementation of copy_str
char *copy_str(char *inStr, short len) {
  char *newStr = malloc((len + 1) * sizeof(char)); // Allocate memory for the new string
  if (newStr == NULL) {
    return NULL;  // Handle memory allocation failure
  }
  for (int i = 0; i < len; i++) {
    newStr[i] = inStr[i];
  }
  newStr[len] = '\0';  // Null-terminate the string
  return newStr;
}

// Implementation of tokenize
char **tokenize(char *s) {
  int num_tokens = count_tokens(s);  // Get the number of tokens
  char **tokens = malloc((num_tokens + 1) * sizeof(char *));  // Allocate space for tokens array (+1 for NULL terminator)
  if (!tokens) return NULL;  // Check for allocation failure

  char *current = s;  // Pointer to iterate through the string
  for (int i = 0; i < num_tokens; i++) {
    current = token_start(current);    // Find the start of the next token
    char *end = token_terminator(current);  // Find the end of the token

    int len = end - current;           // Calculate the token length
    tokens[i] = copy_str(current, len);  // Copy the token into a new string

    current = end;  // Move the current pointer to the end of the token
  }
  tokens[num_tokens] = NULL;  // Null-terminate the array of tokens

  return tokens;
}

// Implementation of print_tokens
void print_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("Token %d: %s\n", i, tokens[i]);
  }
}

// Implementation of free_tokens
void free_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);  // Free each individual token
  }
  free(tokens);  // Free the array of token pointers
}
