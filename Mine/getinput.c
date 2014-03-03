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

char* getString(void);
char getChar(void);
char* getInput(char type);
int getInt(void);

int main(void)
{
	char* input;
//	char type;
//
//	printf ( "What type of input would you like to give?\n" );
//	printf ( "(I)nt, (F)loat, (C)har, (L)ong, (LL)onglong?\n" );
//	printf ( ">>\n" );
//	type = getChar();
//	type = tolower(type);
//
	printf ( "Give me an int!\n>>\n" );
	input = getInt();

	printf ( "You typed: %i\n", input );
	free(input);
}

char* getString(void)
{
	// growable buffer for chars
	string buffer = NULL;

	// capacity of buffer
	unsigned int capacity = 0;

	// number of chars actually in buffer
	unsigned int n = 0;

	// character read or EOF
	int c;

	// iteratively get chars from standard input
	while ((c = fgetc(stdin)) != '\n' && c != EOF)
	{
		// grow buffer if necessary
		if (n + 1 > capacity)
		{
			// determine new capacity: start at 32 then double
			if (capacity == 0)
			{
				capacity = 32;
			}
			else if (capacity <= (UINT_MAX / 2))
			{
				capacity *= 2;
			}
			else
			{
				free(buffer);
				return NULL;
			}

			// extend buffer's capacity
			string temp = realloc(buffer, capacity * sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return NULL;
			}
			buffer = temp;
		}

		// append current character to buffer
		buffer[n++] = c;
	}

	// return NULL if user provided no input
	if (n == 0 && c == EOF)
	{
		return NULL;
	}

	// minimize buffer
	string minimal = malloc((n + 1) * sizeof(char));
	strncpy(minimal, buffer, n);
	free(buffer);

	// terminate string
	minimal[n] = '\0';

	// return string
	return minimal;
}

char getChar(void)
{
	while ( true )
	{
		char c1, c2;
		char* line = getString();

		if (line == NULL)
			return CHAR_MAX;
		
		if (1 == sscanf(line, " %c %c", &c1, &c2))
		{
			free(line);
			return c1; /*  i can be safely used */
		}
		else
		{
			free(line);
			free(c1);
			free(c2);
			printf ( "Retry: " );
		}
	}
}

int getInt(void)
{
	while ( true )
	{
		int n;
		char c;
		char* line = getString();

		if (line == NULL)
			return CHAR_MAX;
		
		if ((1 == sscanf(line, " %n %c", &n, &c)))
		{
			free(line);
			return n; /*  i can be safely used */
		}
		else
		{
			free(line);
			free(c1);
			free(c2);
			printf ( "Retry: " );
		}
	}
}
