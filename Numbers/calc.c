/*
 * =====================================================================================
 *
 *       Filename:  calc.c
 *
 *    Description:  A calculator you can call from the command line
 *
 *        Version:  0.1
 *        Created:  03/15/14 17:44:08
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

void quit(const char message[]) __attribute__((noreturn));
inline double calc(double first, double second, char operator);

int main (int argc, char *argv[])
{
//    if (argc == 0)
//        prompt()
    
    if (argc != 4 && argc > 1) {
        fprintf(stderr, "%d is not enough arguments!\n", argc);
        exit(1);
    }

    double a, b, c;
    char operator, j;
    errno = 0;

    if (argc == 1 || argc == 0)
    {
        printf ( "You didn't enter anything at the command line! Let's fix that.\n" );
        printf ( "Please enter the first number: " );
        a = getDouble();
        printf ( "Please enter the second number: " );
        b = getDouble();
        printf ( "Please give me an operator\n( + - x / ): " );
        operator = getChar();
    }
    else
    {
        a = stringtod(argv[1]); // grab first number
        if (sscanf(argv[2], " %c %c", &operator, &j) != 1) // get operator
            quit ("Couldn't grab operator");
        b = stringtod(argv[3]);
    }

    c = calc(a, b, operator);
    if (__isfinite(c) == 0)
        quit("It's a NaN!");
    else
        printf("%g %c %g == %g", a, operator, b, c);

    return EXIT_SUCCESS;
}

void quit(const char message[])
{
    fprintf(stderr, "%s", message);
    exit(1);
}

double calc(double a, double b, char operator)
{
    switch(operator)
    {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case 'x':
            return (a * b);
        case '/':
            return (a / b);
        default:
            return FP_NAN;
    }
}

