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

char* fib(unsigned int n);
unsigned int bytes_added( int result_of_sprintf );

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Expected usage: ./fib 32 (where 32 is desired digits of fibonacci numbers)");
        exit(EXIT_FAILURE);
    }
    
    unsigned int len = (unsigned int)stringtoint(argv[1]); --len;
    if (len < 3)
        fprintf(stderr, "Need at least 3 digits!");

    char* f = fib(len);
    printf("%s\n", f);

    return EXIT_SUCCESS;
}

char* fib(unsigned int n)
{
    unsigned long long f[n];
    unsigned int i, slen, smem = 8, addlen;
    char* answer;

    f[0] = 0;
    f[1] = 1;
    answer = malloc(smem * sizeof(char));
    slen = bytes_added(snprintf(answer, smem, "%llu, %llu, ", f[0], f[1]));

    for (i = 2; i < n; i++)
    {
        if (f[i - 1] > 0 && f[i - 1] > ULLONG_MAX - f[i - 2])
            return NULL;

        f[i] = f[i - 1] + f[i - 2];
        
        addlen = bytes_added(snprintf(NULL, 0, "%llu, ", f[i]));
        while (strlen(answer) + addlen > (smem / sizeof(char))) {
            smem = smem * 2;
            answer = realloc(answer, smem * sizeof(char));
        }

        slen += bytes_added(snprintf(answer + slen, addlen + 1, "%llu, ", f[i]));
    }

    if (f[n - 1] > 0 && f[n - 1] > ULLONG_MAX - f[n - 2])
         return NULL;

    f[n] = f[n - 1] + f[n - 2];
    addlen = bytes_added(snprintf(NULL, 0, "%llu!", f[n]));

    while (strlen(answer) + addlen > (smem / sizeof(char))) {
        smem = smem * 2;
        answer = realloc(answer, smem);
    }

    slen += bytes_added(snprintf(answer + slen, addlen + 1, "%llu!\n", f[i]));
    
    return answer;
}

unsigned int bytes_added( int result_of_sprintf )
{
    return (result_of_sprintf > 0) ? (unsigned int)result_of_sprintf : 0;
}
