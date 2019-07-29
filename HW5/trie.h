// Sheershak Agarwal
// HW 5
// May 14 2019


#ifndef TRIE_H
#define TRIE_H

#define MAX_LINE 100

struct Trie {
  char* word;
  struct Trie* list[9];
};

typedef struct Trie Trie;
Trie* createTrie();
void add(char* word, Trie* node);
int convertInt(char ch);
void searchWord(Trie* node);
void freeNode(Trie* node);

#endif // TRIE_H
