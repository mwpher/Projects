/*
 * =====================================================================================
 *
 *       Filename:  nextprime.c
 *
 *    Description:  find primes until user stops asking
 *
 *        Version:  0.1
 *        Created:  07/05/14 22:35:25
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
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <matt.h>

long isprime(long num);

int main (int argc, char *argv[]) {
    long prime = 3, factor = 0;
    int n = 2;

    if (argc > 1) {
        fprintf(stderr, "You don't need any arguments; ignoring.\n");
    }
    printf("Prime #1: 2\n");
    
    while (true) {
        factor = isprime(prime);
        while (factor != 0) {
            fprintf(stderr, "%ld is not prime! (found factor in %ld)\n", prime, factor);
            prime++;
            factor = isprime(prime);
        }
        printf("Prime %d: %ld\n", n, prime);
        printf("Continue? (y/n) ");
        char c;
        switch(c = getChar()) {
            case 'n':
            case 'N':
                exit(0);
            case 'y':
            case 'Y':
                break;
        }
        prime++;
    }
    
}

long isprime(long num) {
    static int i;
    for (i = 2; (i < num); i++) {
        if (num % i == 0) {
            return i;
        }
    }
    return 0;
}
