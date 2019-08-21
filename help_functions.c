#include "holberton.h"

/**
  * _strcmp - will compare the equality of two strings
  * @s1: 1st string to compare
  * @s2: second string to compare
  * Return: 1 if strings are equal, 0 otherwise  
  */

int _strcmp(char *s1, char *s2)
{
	/* used to travel through each place of string */
	unsigned int i = 0;

	/* ensures that there is string input */ 
	while (s1[i])
	{
		/* exit loop if strings do not match */
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}

/**
 * _strncpy - copies ones string to another string in memory
 * @origin: destination string to copy from
 * @copied: string to copy to
 * @length: the length to copy
 * Return: original string memory address
 */
char *_strncpy(char *original, char *copied, int length)
{
	int i;

	for (i = 0; i < length && copied[i] != '\0'; i++)
		original[i] = copied[i];

	for ( ; i < length; i++)
		orignal[i] = '\0';

	return (original);
}

/**
 * const_strncpy - copies one constant string to another string
 * @dest: destination string to copy from
 * @src: string to copy to
 * @n: the length to copy
 *
 * Return: the dest memory address
 */
char *const_strncpy(char *original, const char *copied, int length)
{
	int i;

	for (i = 0; i < length && copied[i] != '\0'; i++)
		original[i] = copied[i];

	for ( ; i < length; i++)
		original[i] = '\0';

	return (original);
}

/**
 * const_strlen - gets length of constant string
 * @input_string: string to determine length of
 * Return: length of the constant string
 */
unsigned int const_strlen(const char *input_string)
{
	unsigned int i = 0;

	while (input_string[i])
		++i;
	return (i);
}
/**
 * _strlen - gets the length of a string
 * @str: string to determine the length of
 * Return: length of the string as unsigned int
 */
unsigned int _strlen(char *str)
{
	unsigned int count = 0;

	while (str[count] != '\0')
		++count;

	return (count);
}
