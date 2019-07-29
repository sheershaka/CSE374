/* Sheershak Agarwal
   HW 4
   27 April 2019
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// CONSTANTS
#define MAX_LINE 500
#define MAX_PATTERN 100

// function declaration
void openFile(int fileIndex, char *argv[], int i, int n);

// checks if it has less than 3 arguments.
// iterates through each file and call openFile function.
int main (int argc, char *argv[]) {

  // return -1 if less than three arguments are given
  if (argc < 3) {
    fprintf(stderr, "Less than three arguments passed\n");
    return -1;
  }

  int i = 0, n = 0; // i for ignoring case and n for number lines 

  // match the option given on the command line, start from 1
  for (int j = 1; j < argc; j++) {
    if (strcmp(argv[j], "-i") == 0) {
      i = 1;
    } 
    if (strcmp(argv[j], "-n") == 0) {
      n = 1;
    }
  }

  // iterating through all the files input by user
  for (int j = i+n+2; j < argc; j++) {
    openFile(j, argv, i, n);
  }

  return 0;
}

// open the file at fileIndex, and finds and prints the line matching the pattern
void openFile (int fileIndex, char *argv[], int i, int n) {
  
  // open the file
  FILE* file = fopen(argv[fileIndex], "r"); //pointer to the file
 
  // check if the file exists
  // if not then output a message with file otherwise continue matching patter to file
  if (file == NULL) {
    fprintf(stderr, "File: %s does not exsist.\n", argv[fileIndex]);
  } else {
    char line[MAX_LINE];
    int lineNumber = 0;
    // traversing through each line in the file
    while (fgets(line, MAX_LINE, file)) {
      lineNumber++; //getting the current line number
      char pattern[MAX_PATTERN];
      char tempLine[MAX_LINE];
      strncpy(pattern, argv[i+n+1], strlen(argv[i+n+1]));
      strncpy(tempLine, line, MAX_LINE);
      if (i == 1) { // ignore cases by makinf the line and pattern lowercase
        for(int j = 0; j < strlen(tempLine); j++) {
          tempLine[j] = tolower(tempLine[j]);
	}
	for(int j = 0; j < strlen(pattern); j++) {
          pattern[j] = tolower(pattern[j]);
        }
      }
      // print if the patter is found in the line
      if (strstr(tempLine, pattern) != NULL) {
        if (n == 1) {
          printf("%s: %d: %s", argv[fileIndex], lineNumber, line);
        } else {
          printf("%s: %s", argv[fileIndex], line);
        }
      }
    } 
  }

  // close the file
  fclose(file);
}
