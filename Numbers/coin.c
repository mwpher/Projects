/*
 * =====================================================================================
 *
 *       Filename:  coin.c
 *
 *    Description:  Flip a coin as many times as the user wants
 *
 *        Version:  0.1
 *        Created:  01/30/15 13:27:37
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
#include <limits.h>
#include <matt.h>

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%d is the wrong number of arguments!\n", argc);
        exit(1);
    }

    unsigned int flips;
    const char* errstr;
    unsigned int i;

    flips = (unsigned int)strtonum(argv[1], 1, UINT_MAX, &errstr);

    if(flips <= 1) {
        fprintf(stderr, "Number must be an int from 1 to %d. \n strtonum error: %s", UINT_MAX, errstr);
        exit(EXIT_FAILURE);
    }

    bool myRandomData[flips];
    arc4random_buf(myRandomData, sizeof myRandomData);

    for (i = 0; i < flips; i++) {
        if (myRandomData[i] == true) {
            printf("Heads! ");
        }
        else {
            printf("Tails! ");
        }
        printf(" %u \r\n", myRandomData[i]);
    }

    return EXIT_SUCCESS;
}
