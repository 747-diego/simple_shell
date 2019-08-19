#include "holberton.h"


void type_prompt()

{

	static int firstTime = 1;
	/* i set this as a static variable because static varibles */
	/* preserve its value until this function is called again */
	/* which means even though we set it zero at the end of the if statement */
	/* it will go back to always being 1 so that it stays true */

	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
	/* cool feature i found on google, everytime the function is called */
	/* it frist clears the whole terminal for a fresh start */
	/* using these ANSI characters */

	if (firstTime) /* this only happens only at the very begining of our terminal */

	{
		write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
		firstTime = 0; /* we set it to 0 so that it wont do it again in the current terminal*/
	}

	putchar('$'); /* After we clear the screen */
	putchar(' '); /* we display the prompt */
}
