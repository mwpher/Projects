/*
 * =====================================================================================
 *
 *       Filename:  vartest.c
 *
 *    Description:  
 *
 *        Version:  0.1
 *        Created:  03/15/14 22:31:17
 *       Revision:  none
 *       Compiler:  Clang
 *
 *         Author:  Matthew Pherigo (mwp), hybrid120@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    printf ( "argc is %d\n", argc );
    
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
