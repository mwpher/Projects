/*
 * =====================================================================================
 *
 *       Filename:  fib1.c
 *
 *    Description:  
 *
 *        Version:  0.1
 *        Created:  03/19/14 21:24:02
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
#include <limits.h>

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
    
    unsigned int len = (unsigned int)stringtoint(argv[1]); --len;
    if (len < 3)
        fprintf(stderr, "Need at least 3 digits!");

    unsigned long long fib[len];
    fib[0] = 1;
    fib[1] = 1;

    for (unsigned int i = 2; i <  len; i++)
    {
        if (fib[i - 1] > 0 && fib[i - 1] > ULLONG_MAX - fib[i - 2])
            return -1;

        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (unsigned int i = 0; i < (len - 1); i++)
    {
        printf("%llu, ", fib[i]);
    }
    printf("%llu\n", fib[len]);
}
