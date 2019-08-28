#include "holberton.h"
/**
 * prompt_handler - handles signals and write the prompt
 * @sig: signal to handle
 *
 * Return: void
 */
void prompt_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - simple shell recreation
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on exit, 1 if any failures happen
 */
int main(int argc, char **argv, char **env)
{
	char *buffer,  **commands;
	size_t length;
	ssize_t characters;
	char *prompt = "$ ", *exit_command = "exit",
	 *env_command = "env", *cd_command = "cd";
	pid_t child;
	struct stat fileStat;
	int status, count;
	(void)argc;

	buffer = NULL, length = 0, count = 0;
	if (isatty(STDIN_FILENO)) /* write prompt only if it's from standard input */
		write(STDOUT_FILENO, prompt, 2);
	signal(SIGINT, prompt_handler); /*signal kill for ctrl + c */
	while ((characters = getline(&buffer, &length, stdin))) /* while loop contining forever */
	{
		if (characters == EOF) /* checks for end of file */
			end_of_file(buffer);
		++count; /* counting the number of times the prompt shows up to display correct error */
		commands = array_from_strtok(buffer); /* collects commands from prompt and store in a double pointer array */

		if (_strcmp(cd_command, commands[0]))
		{
			if (cd(commands[1]) < 0)
				perror(commands[1]);
			continue;
		}
		child = fork(); /*create a new process */
		if (child == -1)
			fork_fail();
		if (child == 0)
		{
			if (commands == NULL)  /* check if commands is NULL or all empty spaces */
				command_is_null(buffer);
			else if (_strcmp(exit_command, commands[0])) /* check if the command is an EXIT to exit the shell */
				exit_out(buffer, commands);
			else if (_strcmp(env_command, commands[0])) /* check if the command is ENV to print out environment variables */
				env_out(buffer, commands, env);
			else if (stat(commands[0], &fileStat) == 0) /* check if the command is a full path to an executable file */
				execve(commands[0], commands, NULL);
			else /* check all $PATH directories for executable commands */
				create_path(commands, buffer, env, argv, count);
		}
		else  /* Free mallocs from tokens we created */
		{
			wait(&status);  /* wait for the child process to finish */
			if (commands == NULL)
				parent_free_buff_commands(buffer, commands);
			else if (_strcmp(exit_command, commands[0])) /* if exit, free buffer and commands, then exit program */
				exit_out(buffer, commands);
			else /*free buffer and commands double ptr from parent process */
				parent_free_buff_commands(buffer, commands);
		}
		length = 0; /* reset length and buffer for getline funciton */
		buffer = NULL;
		if (isatty(STDIN_FILENO)) /* write outs prompt only if from standard input */
			write(STDOUT_FILENO, prompt, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
