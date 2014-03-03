/*
 * =====================================================================================
 *
 *       Filename:  sscanftest.c
 *
 *    Description:  find out is sscanf checks if value is too big
 *
 *        Version:  1.0
 *        Created:  03/02/14 17:24:25
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
#include <errno.h>
#include <limits.h>

int stringtoint(char* string, int* errvalptr);

int main(void)
{
	char* toobig;
	char* ntoobig;
	int i;
	char c;
	int ret;
	toobig = "999999999999999999999999999999999999";
	ntoobig = "-999999999999999999999999999999999999";
	
	printf ( "Starting tests with sscanf...\n" );
	ret = sscanf(toobig, " %i %c", &i, &c);
	printf("Positive overflow: return %i, int %i\n", ret, i);

	ret = sscanf(ntoobig, " %i %c", &i, &c);
	printf("Negative overflow: return %i, int %i\n", ret, i);
	printf ( "\n" );
	printf ( "Now using strtonum...\n" );
	int err;
	i = stringtoint(toobig, &err);
	printf ( "Positive overflow: returned int %i, err %i\n", i, err );

	i = stringtoint(ntoobig, &err);
	printf ( "Negative overflow: returned int %i, err %i\n", i, err );
}

int stringtoint(char* string, int* errvalptr)
{
	const char* err;
	long long ll;
	int answer;

	ll = strtonum(string, LLONG_MIN, LLONG_MAX, &err);
	if (err != NULL)
	{
		*errvalptr = 1;
		fprintf(stderr, "strtonum error: %s\n", err);
		return 0;
	}

	if (ll > INT_MAX)
	{
		*errvalptr = 1;
		return 0;
	}
	else if (ll < INT_MIN)
	{
		*errvalptr = -1;
		return 0;
	}
	answer = (int)ll;
	*errvalptr = 0;
	return answer;
}
