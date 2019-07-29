// Sheershak Agarwal
// HW 5
// May 14 2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

void searchWord(Trie* trie);

// main fuction
// check arguments and reads the dictionary to make a Trie
// finds the T9onyms from the user's input
// and frees the space it used at the end 
int main(int argc, char *argv[])
{
  // check the number of arguments
  if (argc != 2) {
    fprintf(stderr, "Invalid number of arguments\n");
    exit(1);
  }
  // initialize trie
  Trie* trie = createTrie();

  // open the file file and check if it exists
  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", argv[1]);
    exit(1);
  }
  // getting the word and adding to the trie
  char line[MAX_LINE];
  while (fgets(line, MAX_LINE, f)) {
    add(line, trie);
  }
  fclose(f); //close the file after use
  searchWord(trie); // search the word in the trie
  freeNode(trie); // free the trie node after use
  return 0;
}

// searches the words from stdin and prints the result
void searchWord(Trie* trie) {
  char input[MAX_LINE];
  Trie* node = trie;
  printf("Enter \"exit\" to quit.\n");
  while (1) {
    printf("Enter Key Sequence (or \"#\" for next word):\n> ");
    scanf("%s", input);
    if (strcmp(input, "exit") == 0) {
      // exit the application
      break;
    } else if (input[0] == '#') {
      // iterating to the position of word 
      // according to the number of hashes
      for (int i = 0; i < strlen(input); i++) {
	if (node!= NULL && input[i] == '#') {
	  node = node->list[8];
	}
      }
      // print the iterated word
      if (node != NULL) {
	printf("\'%s'\n", node->word);
      } else {
	printf("There are no more T9onyms\n");
      }
    } else {
      node = trie;
      int hash = 0;
      for (int i = 0; i < strlen(input); i++) {
	int index = (int)input[i]; //converting char into ascii int
	if (index < 50 || index > 57 || node == NULL) { // 50 for 2 nd 57 for 9
	  break;
	}
	if (index == 35) { //input[i] == '#'
	  node = node->list[8];
	  hash = 1;
	} else {
	  node = node->list[index - 50];
	}
      }
      // print results
      if (node == NULL || node->word == NULL) {
	if (hash == 1) {
	  printf("There are no more T9onyms\n");
	} else {
	  printf("Not found in the current directory\n");
	}
      } else {
	printf("\'%s\'\n", node->word);
      }
    }
  }
}
