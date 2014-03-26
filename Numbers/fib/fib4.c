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

int bytes_added( int result_of_sprintf );


int main(int argc, char* argv[])
{
    if (argc != 2)
        fprintf(stderr, "Expected usage: ./fib 32 (where 32 is desired digits of fibonacci numbers)");
    
    unsigned int len = (unsigned int)stringtoint(argv[1]); --len;
    if (len < 3)
        fprintf(stderr, "Need at least 3 digits!");

    unsigned long long f[len];
    //fib(f[0], len);
    unsigned int i;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= len; i++)
    {
        if (f[i - 1] > 0 && f[i - 1] > ULLONG_MAX - f[i - 2])
            return -1;

        f[i] = f[i - 1] + f[i - 2];
    }
    const int MAX_BUF = 1000;
    int z = snprintf(NULL, MAX_BUF, "%llu, ", f[len]); // What's the biggest chunk we need?
    unsigned int size = (z > 3) ? (unsigned int)z : 32; 
    char* buffer = malloc((size + 1) * sizeof(char));
    char* string = malloc((size + 1) * sizeof(char));
    int length = 0;
    int slength = 0;
    for (i = 0; i <= len; ++i)
    {
        length += bytes_added(snprintf(buffer, MAX_BUF, "%llu, ", f[i]));
        if (strlen(buffer) + strlen(string) > size)
        {
            size += strlen(buffer);
            string = realloc(string, (size + 1) * sizeof(char));
        }
        if(i < len){
        slength += bytes_added(snprintf(string+slength, MAX_BUF, "%llu, ", f[i]));
        }
        else{
        slength += bytes_added(snprintf(string+slength, MAX_BUF, "%llu\n", f[i]));
        }
    }

    return EXIT_SUCCESS;
}

int bytes_added( int result_of_sprintf )
{
    return (result_of_sprintf > 0) ? result_of_sprintf : 0;
}

//void fib(unsigned long long *ptr, unsigned int size);
//{
//    unsigned long long f[n];
//    unsigned int i;
//
//    f[0] = 0;
//    f[1] = 1;
//    printf("%llu, %llu, ", f[0], f[1]);
//
//    for (i = 2; i <= n; i++)
//    {
//        if (f[i - 1] > 0 && f[i - 1] > ULLONG_MAX - f[i - 2])
//            return -1;
//
//        f[i] = f[i - 1] + f[i - 2];
//    }
//
//    return f[];
//}
