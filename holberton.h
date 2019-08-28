#ifndef SHELL_HEADER
#define SHELL_HEADER


/* Headers */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */

void read_command(char cmd[], char *par[]);
void type_prompt();






#endif
