#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "execCmds.h"

// execute the commands from the command line on the array
//
// parameters:
// - lines: the array of strings
// - map: the object that maps command names to functions
// - argv: the command-line arguments (with out the first, the command name)
void executeCommands(char** lines, commandMap* map, char* argv[]) {
  int i;
  // loop through each command-line argument
  for (i = 0; argv[i] != NULL; i++) {
    // get the command name
    char* cmdName = argv[i];
    // look for a match; if found execute the corresponding function
    commandMap* cm;
    for (cm = map; cm->fcn != NULL; cm++) {
      if (strcmp(cm->name, cmdName) == 0) {
	cm->fcn(lines);
	break;
      }
    }
    // if no match was found, give an error message
    if (cm->fcn == NULL) {
      fprintf(stderr, "Illegal command name: '%s'.\n", cmdName);
    }
  }
}
