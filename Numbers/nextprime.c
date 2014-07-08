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

 /* prototypes */
long isprime(long num);

/*-----------------------------------------------------------------------------
 *  This program has three different modes:
 *
 *  - interactive (give numbers while user wants them)
 *      ./nextprime
 *
 *  - stream (give as many primes as user requested in command line argument)
 *      ./nextprime 42
 *
 *  - file (output requested number of primes to specified file)
 *      ./nextprime 42 primes.txt
 *-----------------------------------------------------------------------------*/

int main (int argc, char *argv[]) {
    long prime = 2, factor = 0;
    int n = 1;
    errno = 0;

    if (argc == 1) { /* Interactive mode */
        while (true) {
            factor = isprime(prime);
            while (factor != 0) {
                fprintf(stderr, "%ld is not prime! (found factor in %ld)\n", prime, factor);
                prime++;
                factor = isprime(prime);
            }
            printf("Prime #%d: %ld\n", n, prime);
            printf("Continue? (y/n) ");
            char c;
            switch(c = getChar()) {
                case 'n':
                case 'N':
                    exit(0);
                case 'y':
                case 'Y':
                    break;
                default:
                    continue;
            }
            prime++; n++;
        }
    }

    else if (argc == 2) { /* stream mode */
            int iterations;
            iterations = stringtoint(argv[1]);
            if (errno != 0) {
                fprintf(stderr, "Error in stringtoint: ");
                ERROR; exit(EXIT_FAILURE);
            }
            iterations++;
            for (n = 1; n < iterations; n++) {
                factor = isprime(prime);
                while (factor != 0) {
                    fprintf(stderr, "%ld is not prime! (found factor in %ld)\n", prime, factor);
                    prime++;
                    factor = isprime(prime);
                }
                printf("Prime #%d: %ld\n", n, prime);
                prime++;
            }
    }

    else if (argc == 3) { /* File mode */
        FILE *fp;                       /* output-file pointer */
        char *fp_file_name = argv[2];   /* output-file name    */
        int iterations;

        fp	= fopen(fp_file_name, "w"); /* open output file    */
        if (fp == NULL) {
            fprintf (stderr, "couldn't open file '%s'; %s\n",
                    fp_file_name, strerror(errno));
            exit (EXIT_FAILURE);
        }

        iterations = stringtoint(argv[1]);
        if (errno != 0) {
            fprintf(stderr, "Error in stringtoint: ");
            ERROR; fclose(fp); exit(EXIT_FAILURE);
        }
        iterations++;
        for (n = 1; n < iterations; n++) {
            factor = isprime(prime);
            while (factor != 0) {
                fprintf(fp, "# %ld / %ld\n", prime, factor);
                prime++;
                factor = isprime(prime);
            }
            fprintf(fp, "%d: %ld\n", n, prime);
            prime++;
        }
        if (fclose(fp) == EOF) {		/* close output file   */
            fprintf (stderr, "couldn't close file '%s'; %s\n",
                fp_file_name, strerror(errno));
            exit (EXIT_FAILURE);
        }
        printf("Done!\n");
    }

    else { /* 360 noscope mode */
        fprintf(stderr, "wat do\n");
        exit(360);
    }
}

long isprime(long num) {
    static int i; /* loop through possible factors of num */
    for (i = 2; (i < num); i++) {
        if (num % i == 0) {
            return i;
        }
    }
    return 0;
}

