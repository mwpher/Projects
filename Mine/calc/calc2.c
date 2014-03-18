/*
 * =====================================================================================
 *
 *       Filename:  calc2.c
 *
 *    Description:  A more betterly calculator
 *                  **NOW WITH FLOATS**
 *
 *        Version:  0.1
 *        Created:  03/08/14 15:56:58
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
#include <errno.h>
#include <matt.h>
#include <stdbool.h>
#include <ctype.h>

static bool ok;

double add(void);
double sub(void);
double mult(void);
double divide(void);

int main(void)
{
    char choice;
    double answer;

    while ( true )
    {
        ok = false;
        printf ( "Let's calculate!\n" );
        printf ( "Add (a)\n" );
        printf ( "Subtract (s)\n" );
        printf ( "Multiply (m)\n" );
        printf ( "Divide (d)\n" );
        printf ( "Quit (q)\n" );
        printf ( "\n" );

        do
        {
            printf ( "\n" );
            printf ( ">" );
            choice = getChar();
            choice = (char)tolower(choice);
            switch (choice)
            {
                case 'a':
                    answer = add();
                    printf ( "%g!\n\n", answer );
                    break;
                case 's':
                    answer = sub();
                    printf ( "%g!\n\n", answer );
                    break;
                case 'm':
                    answer = mult();
                    printf ( "%g!\n\n", answer );
                    break;
                case 'd':
                    answer = divide();
                    printf ( "%g!\n\n", answer );
                    break;

                case 'q':
                    exit(EXIT_SUCCESS);
            }
        } while (ok == false);
    }
}

double add(void)
{
    double a;
    double b;
    double c;

    printf ( "Please enter the first number: " );
    a = getDouble();
    printf ( "Please enter the second number: " );
    b = getDouble();

    printf ( "%g + %g = ", a, b );
    
    c = a + b;
    ok = true;
    return c;
}

double sub(void)
{
    double a;
    double b;
    double c;

    printf ( "Please enter the first number: " );
    a = getDouble();
    printf ( "Please enter the second number: " );
    b = getDouble();

    printf ( "%g - %g = ", a, b );
    
    c = a - b;
    ok = true;
    return c;
}

double mult(void)
{
    double a;
    double b;
    double c;

    printf ( "Please enter the first number: " );
    a = getDouble();
    printf ( "Please enter the second number: " );
    b = getDouble();

    printf ( "%g * %g = ", a, b );
    
    c = a * b;
    ok = true;
    return c;
}

double divide(void)
{
    double a;
    double b;
    double c;

    printf ( "Please enter the first number: " );
    a = getDouble();
    printf ( "Please enter the second number: " );
    b = getDouble();

    printf ( "%g / %g = ", a, b );
    
    c = a / b;
    ok = true;
    return c;
}
