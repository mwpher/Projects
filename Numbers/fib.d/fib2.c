/*
 * =====================================================================================
 *
 *       Filename:  fib.c
 *
 *    Description:  Calculates the fibonacci sequence to the length given by argv
 *
 *        Version:  0.1
 *        Created:  03/18/14 11:54:37
 *       Revision:  none
 *       Compiler:  Clang
 *
 *         Author:  Matthew Pherigo (mwp), hybrid120@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <matt.h>
#include <string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    if (argc != 2)
        fprintf(stderr, "Expected usage: ./fib 32 (where 32 is desired digits of fibonacci numbers)");

    int len = (stringtoint(argv[1])); --len;
    if (len < 3)
        fprintf(stderr, "Need at least 3 digits!");

    int fib[len];
    fib[0] = 1;
    fib[1] = 1;

    for (int i = 1; i < (len - 1); ++i)
    {
        fib[i + 1] = fib[i - 1] + fib[i];
    }
    
    int z = snprintf(NULL, 1, "%d, ", fib[len]);
    if (z <= 0)
    {
       fprintf(stderr, "Couldn't get size!");
       return -1;
    }
    unsigned int mbufsize = (unsigned int)z;
    unsigned int x = 32;
    char* result = malloc(sizeof(char) * (x + 1));
    char* buf = malloc(sizeof(char) * (unsigned int)mbufsize);

    for (int i = 0; i < len; ++i)
    {
        int ret = snprintf(buf, mbufsize, "%d, ", fib[i]);
        if (ret > (int)mbufsize || ret <= 0)
        {
            fprintf(stderr, "Something went wrong!");
            return -1;
        }
        if ((strlen(result) + strlen(buf)) > (sizeof(result) / sizeof(char)))
            result = realloc(result, (sizeof(char) * (x + 1)));
        result = strncat(result, buf, strlen(buf));
    }

    printf ( "%s\n", result );

    return EXIT_SUCCESS;
}
