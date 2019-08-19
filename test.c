#include "holberton.h"

int main()

{


	char cmd[100], command[100], *parameters[20]; /* 2 arrays to hold the commands and array of pointers to hold the parameters */


	/* defines enviroment  variables */
	char *envp[] = { (char *) "PATH=/bin", 0};


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
			strcpy(cmd, "/bin/"); /* coppies the bin directory into cmd array */
			strcat(cmd, command); /* concatenates that command into cmd array */
			execve(cmd, parameters, envp); /* executing command coming from envp */
		}

		if (strcmp(command, "exit") == 0) /* if exit command is typed in.exit the loop */

		{

			/* printf("Goodbye\n"); /* testing if exit cmd works */
			break;
		}

	}

	return (0);
}
