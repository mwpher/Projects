/*
 * =====================================================================================
 *
 *       Filename:  calcdumb2.c
 *
 *    Description:  adder
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

int main(void)
{
	int a;
	int b;
	int c;

	printf ( "Let's add two integers!\n\n" );
	printf ( "Give me the first integer: " );
	a = GetInt();
	printf ( "Give me the second integer: " );
	b = GetInt();
	printf ( "You gave me %i and %i.\n", a, b );
	c = a + b;
	printf ( "That adds up to %i!\n", c );
	return 0;
}
