/*
 * =====================================================================================
 *
 *       Filename:  calc1.c
 *
 *    Description:  int calculator
 *
 *        Version:  1.0
 *        Created:  02/24/14 21:54:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew  Pherigo (mwp), hybrid120@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
 *  --- HEADERS HERE ---
 *-----------------------------------------------------------------------------*/
static int answer;
static bool satisfied;
int add(void);


/*-----------------------------------------------------------------------------
 *  FUNCTION main()
 *-----------------------------------------------------------------------------*/
int main(void)
{
	char choice;
	extern bool satisfied;

	printf ( "Which would you like to do?\n" );
	printf ( "Add.     (a)\n" );
	printf ( "Subtract (s)\n" );
	
	do {
		extern int answer;
		printf ( "\n" );
		printf ( ">" );
		choice = GetChar();


		switch (choice) {
			case 'a':	
				answer = add();
				break;

			case 's':	
				fprintf ( stderr, "Not implemented yet!\n" );
				break;

		//	case :	
		//		break;

			default:
				printf ( "Not a valid answer!\n" );
				break;
		}	
	} while (satisfied != true);
	printf ( "Answer was %i\n", answer );
}


/*-----------------------------------------------------------------------------
 *  FUNTION add()
 *-----------------------------------------------------------------------------*/
int add(void)
{
	int a;
	int b;
	int c;
	extern bool satisfied;

	printf ( "Let's add two integers!\n\n" );
	printf ( "Give me the first integer: " );
	a = GetInt();
	printf ( "Give me the second integer: " );
	b = GetInt();
	printf ( "You gave me %i and %i.\n", a, b );
	c = a + b;
	satisfied = true;

	return c;
}
