#ifndef EXEC_H

#define EXEC_H

// function type for our command function
typedef void commandFcn(char**);

// struct the that maps strings to functions
typedef struct {
  char* name;
  commandFcn* fcn;
} commandMap;

extern void executeCommands(char** lines, commandMap* map, char* argv[]);

#endif
