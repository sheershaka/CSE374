// Sheershak Agarwal
// HW 5
// May 14 2019


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

// create a NULL Trie with all values to be null.
Trie* createTrie() {
  Trie* node = (Trie*) malloc(sizeof(Trie));
  if (node == NULL) {
    fprintf(stderr, "Error while assigning space\n");
    exit(1);
  }
  node->word = NULL;
  for (int i = 0; i < 9; i++) {
    node->list[i] = NULL;
  }
  return node;
}

// adding the words in the file to the trie
void add(char* word, Trie* node) {
  Trie* temp = node;
  int len = strlen(word);
  if(word[len-1] == '\n') {
    word[len-1] = '\0';
  }
  for (int i = 0; i < strlen(word); i++) {
    int index = convertInt(word[i]) - 2;
    if (temp->list[index] == NULL) {
      temp->list[index] = createTrie();
    }
    temp = temp->list[index];
  }
  while (temp->word != NULL) {
    if (temp->list[8] == NULL) {
      temp->list[8] = createTrie();
    }
    temp = temp->list[8];
  }
  temp->word = (char*) malloc(strlen(word) * sizeof(char));
  if (temp->word == NULL) {
    fprintf(stderr, "Error while assigning space\n");
    exit(EXIT_FAILURE);
  }
  strncpy(temp->word, word, strlen(word));
}

// convert the characters to T9 integers and returns it
int convertInt(char ch) {
  if (ch == 'a'|| ch == 'b' || ch == 'c') {
    return 2;
  } else if (ch == 'd' || ch == 'e' || ch == 'f') {
    return 3;
  } else if (ch == 'g' || ch == 'h' || ch == 'i') {
    return 4;
  } else if (ch == 'j' || ch == 'k' || ch == 'l') {
    return 5;
  } else if (ch == 'm' || ch == 'n' || ch == 'o') {
    return 6;
  } else if (ch == 'p' || ch == 'q' || ch == 'r' || ch == 's') {
    return 7;
  } else if (ch == 't' || ch == 'u' || ch == 'v') {
    return 8;
  } else if (ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z') {
    return 9;
  } else {
    return 0;
  }
}

// free the space occupied by the trie
void freeNode(Trie* node) {
  for (int i = 0; i < 9; i++) {
    if (node->list[i] != NULL) {
      freeNode(node->list[i]);
    }
  }
  if (node->word != NULL) {
    free(node->word);
  }
  free(node);
}
