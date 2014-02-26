#include <stdlib.h>
#include <stddef.h>
#include "readLine.h"

// helper method: reads somewhere in the middle of a line
//
// parameters:
// - soFar the number of characters read in so far.
// 
// returns:
// - a malloc'd string where all characters from position 'soFar' and
//   beyond have been initialized
// - NULL, if there were no characters to read
static char *helpReadLine(int soFar) {
  int ch;
  char *rtnVal;
  ch = getchar(); // read a character
  if (ch < 0 && soFar == 0) {
    // end of file, and no characters read so far: return NULL
    return NULL;
  }
  else if (ch == '\n') {
    // found a newline malloc a properly size memory block for the string;
    // set "current character" to 0 so that null byte terminates
    rtnVal = malloc(soFar+1);
    ch = 0;
  }
  else {
    // found something else, recurse to get more
    rtnVal = helpReadLine(soFar+1);
  }
  // update the current position with the current character
  rtnVal[soFar] = ch;

  // return the malloc'd string
  return rtnVal;
}

// reads a line of text from standard input
char* readLine(void) {
  return helpReadLine(0);
}

// reads lines from standard input, allocating an array
//
// parameter:
// - soFar the number of lines read so far
//
// returns: a null-terminated array
static char** helpReadLines(int soFar) {
  char* str;
  char** rtnVal;
  str = readLine(); // read a line
  if (str == NULL) {
    // end of file: allocate the memory
    rtnVal = malloc(soFar+1);
  }
  else {
    // not at end: recurse
    rtnVal = helpReadLines(soFar+1);
  }

  // set the current entry
  rtnVal[soFar] = str;

  // return the array
  return rtnVal;
}

// read all the lines of text from standard input
char** readLines(void) {
  return helpReadLines(0);
}
