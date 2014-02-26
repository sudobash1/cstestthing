#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "readLine.h"
#include "execCmds.h"

// print the elements in the array, up to (but not including) the first
// NULL entry
void printLines(char** a) {
  int i;
  for (i = 0; a[i] != NULL; i++) {
    printf("%s\n", a[i]);
  }
}

void reverseLines(char** a){
    int i, j;
    char* tmp;

    //Find end of list
    for (i=0; a[i] != NULL; ++i){}
    --i;

    //reverse the list
    for (j=0; i > j;){
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        --i; ++j;
    }
}

void removeIdenticalLines(char** a){
    int i, j;
    for (i = 0; a[i] != NULL; ++i){
        //found a duplicate, remove it.
        if (i && !strcmp(a[i], a[i-1])){
            for(j = i; a[j] != NULL; ++j){
                a[j]=a[j+1];
            }
        }
    }
}

// our array that tells how command-strings map to functions
commandMap map[] = {
  {"-p", printLines},
  {"-r", reverseLines},
  {"-i", removeIdenticalLines},
  {NULL, NULL},
};

// main function
int main(int argc, char* argv[]) {
  // read lines from standard input
  char** lines = readLines();

  // execute each command on the command line
  executeCommands(lines, map, argv+1);

  // exit with "success"
  return EXIT_SUCCESS;
}
