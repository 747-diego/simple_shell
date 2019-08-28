#include "holberton.h"

int main(int argc, char **argv, char **env)
{


	char cmd[1000], command[1000], *parameters[200]; /* 2 arrays to hold the commands and array of pointers to hold the parameters */


	/* defines enviroment  variables */
	/* char *envp[] = { (char *) "PATH=/bin", 0}; */


	while (1) /* display prompt forever */

	{
		type_prompt(); /* display prompt */
		read_command(command, parameters); /* read input from terminal */
		if (fork() != 0) /* creates parent */

		{
			wait(NULL); /* waiting for child */
		}

		else

		{
			strcpy(cmd, "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games"); /* coppies the bin directory into cmd array */ 
			strcat(cmd, command); /* concatenates that command into cmd array */
			execve(cmd, parameters, env); /* executing command coming from env */
		}

		if (strcmp(command, "exit") == 0) /* if exit command is typed in.exit the loop */

		{

			/* printf("Goodbye\n"); /* testing if exit cmd works */
			break;
		}

	}

	return (0);
}
