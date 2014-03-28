/*
 * =====================================================================================
 *
 *       Filename:  collatz.c
 *
 *    Description:  collatz conjecture
 *
 *        Version:  0.1
 *        Created:  03/26/14 14:58:16
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
#include <limits.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Expected usage: ./collatz 42 (where 42 is desired starting point for Collatz Conjecture)");
        exit(EXIT_FAILURE);
    }
    const char* errstr;
    long long start = strtonum(argv[1], LLONG_MIN, LLONG_MAX, &errstr);
    
    if(start <= 1)
    {
        fprintf(stderr, "Number must be an int greater then 1. \n strtonum error: %s", errstr);
        exit(EXIT_FAILURE);
    }

    unsigned long long num = (unsigned long long)start;
    unsigned long steps;

    printf("start: %llu\n", num);

    for(steps = 0; num != 1; ++steps)
    {
        if (num % 2)
            num = (num * 3) + 1;
        else
            num = num / 2;
        printf("%lu: %llu\n", steps, num);
    }

    printf("%lu steps taken to reach 1\n", steps);

    return EXIT_SUCCESS;
}

