/*
 * =====================================================================================
 *
 *       Filename:  fib3.c
 *
 *    Description:  
 *
 *        Version:  0.1
 *        Created:  03/20/14 10:31:08
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

int fib(unsigned int n);

int main(int argc, char* argv[])
{
    if (argc != 2)
        fprintf(stderr, "Expected usage: ./fib 32 (where 32 is desired digits of fibonacci numbers)");
    
    unsigned int len = (unsigned int)stringtoint(argv[1]); --len;
    if (len < 3)
        fprintf(stderr, "Need at least 3 digits!");

    fib(len);

    return EXIT_SUCCESS;
}

int fib(unsigned int n)
{
    unsigned long long f[n];
    unsigned int i;

    f[0] = 0;
    f[1] = 1;
    printf("%llu, %llu, ", f[0], f[1]);

    for (i = 2; i < n; i++)
    {
        if (f[i - 1] > 0 && f[i - 1] > ULLONG_MAX - f[i - 2])
            return -1;

        f[i] = f[i - 1] + f[i - 2];

        printf("%llu, ", f[i]);
    }

    if (f[n - 1] > 0 && f[n - 1] > ULLONG_MAX - f[n - 2])
         return -1;

    f[n] = f[n - 1] + f[n - 2];
    printf("%llu!\n", f[n]);
    
    return 0;
}
