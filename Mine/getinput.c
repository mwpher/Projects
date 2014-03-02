/*
 * =====================================================================================
 *
 *       Filename:  getinput.c
 *
 *    Description:  Trying getting input from user
 *
 *        Version:  1.0
 *        Created:  03/01/14 18:16:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Pherigo (mwp), hybrid120@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

char* getinput(void);

int main(void)
{
	char* input;

	printf ( "Give me input!\n>>\n" );
	input = getinput();

	printf ( "You typed: %s\n", input );
}

char* getinput(void)
{
	char line[256];
	char* s = (malloc(sizeof(line)));

	if (fgets(line, sizeof(line), stdin)) 
	{
		if (1 == sscanf(line, "%s", s))
			return s; /*  i can be safely used */
	}
	
	return NULL;
}
