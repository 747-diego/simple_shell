#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* prompt.c */
void prompt_handler(int sig);
int cd(char *path);

/* _strtok.c */
unsigned int find_command_length(char *s);
char **array_from_strtok(char *str);

/* helperfunctions.c */
char *_strncpy(char *dest, char *src, int n);
char *_strncpyconst(char *dest, const char *src, int n);
unsigned int _strlen_const(const char *name);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);

/* habitat.c */
unsigned int find_semis(char *path);
char **store_env_variables(char *fir_com, char **environ);
char *_getenv(const char *name, char **environ);
char *_strncpycmd(char *dest, char *src, char *command, int n, int c);
void print_env(char **environ);

/*free_all.c */
void free_all_double_ptr(char **d_ptr);

/*errors.c*/
void build_error_message(char **av, char *fir_com, int count);
int _puterror(char c);
void end_of_file(char *buffer);
void fork_fail(void);

/*childs_play.c */
void command_is_null(char *buffer);
void exit_out(char *buffer, char **commands);
void env_out(char *buffer, char **commands, char **env);
void parent_free_buff_commands(char *buffer, char **commands);
void create_path(char **commands, char *buffer, char **env, char **argv, int count);

#endif /* _HOLBERTON_H_ */
