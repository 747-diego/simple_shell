#include "holberton.h"

/**
* read_command - function that returns commands and its parameters
* @cmd - command input by the user
* @par - the following argument after command by the user
*/


void read_command(char cmd[], char *par[])
{

	char line[1024]; /* custom size array of 1024 */
	char *array[100]; /* custom size array of 100 */
	char *tokenized; /* varible will hold what strtok had parsed */

	int count = 0;
	int index1 = 0;
	int index2 = 0;
	int charINPUT = 0;;

	while (1)

	{
		charINPUT = fgetc(stdin); /* fgetc gets the users input */
		/* it reads the next character from stream and returns */
		/* it as an unsigned char cast to an "int", or EOF */

		line[count++] = (char)charINPUT; /* we then typecast the unsigned int to char */
		/* so now we set the line qual to the number of characters */

		if (charINPUT == '\n')
			break;
	}

	if (count == 1)
		return;

	tokenized = strtok(line, " \n"); /* breaking the line into tokens */

	while (tokenized != NULL) /* parsing the line into individual words */

	{
		array[index1++] = strdup(tokenized); /* placing the tokens into the array on by one */
		tokenized = strtok (NULL, " \n");
	}

	strcpy(cmd, array[0]); /* first word in the line is placed in the cmd arrary */

	for (index2 = 0; index2 < index1; index2++)

	{
		par[index2] = array[index2];
	}

	par[index1] = NULL; /* setting equal to NULL terminates the parameter list */

	/* this is returned to the calling function inside the refrenced parameter array *par[] */
}
