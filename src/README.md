
# Tokenizer Project

## Overview
This Tokenizer project is designed to analyze and separate strings into a
series of tokens. It handles various string inputs, identifying and
categorizing parts of the strings based on predefined rules.

## Features
- **Token Identification:** Recognizes different types of tokens within a
provided string based on characters and their arrangements, such as words,
numbers, and punctuation.
- **Linked List History:** Utilizes a linked list structure to maintain a
history of all tokens processed during a session, allowing for retrieval and
review.
- **Dynamic Memory Management:** Allocates and frees memory dynamically to
efficiently handle varying lengths and quantities of strings.

## How It Works
1. **Input Reading:** The program reads input strings from the user, waiting
for input with a simple prompt.
2. **Tokenization Process:**
   - **Character Classification:** Each character is classified as a space,
   alphanumeric, or special character to determine token boundaries.
      - **Token Extraction:** Extracts tokens by identifying transitions from
      one character class to another, collecting characters between these
      transitions.
      3. **History Management:**
         - Each token extracted is stored in a linked list, which maintains
	 the history of tokens.
	    - Users can retrieve past tokens based on their position in the
	    history.

## Usage
1. Compile the project using a C compiler, ensuring that `tokenizer.c`,
`history.c`, and any other related files are included.
2. Run the compiled program. It will prompt you to enter strings for
tokenization.
3. After entering each string, the tokenizer will display the tokens and wait
for the next input.
4. Special commands may be used to interact with the token history (e.g.,
retrieving the nth token).

## Components
- `tokenizer.h` and `tokenizer.c`: Contains the logic for breaking strings
into tokens and classifying characters.
- `history.h` and `history.c`: Manages the linked list that stores tokens for retrieval.
