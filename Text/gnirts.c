/*
 * =====================================================================================
 *
 *       Filename:  gnirts.c
 *
 *    Description:  Take a string from user and read it backwards
 *
 *        Version:  0.1
 *        Created:  07/08/14 19:47:59
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
#include <string.h>

int main(int argc, char* argv[]) {
    unsigned int len = 0;
    unsigned int max_len = 141;
    unsigned int n = 0;
    unsigned int spacecounter = 0;
    char buffer[max_len];
    char* gnirts = NULL;
    char* string = NULL;

    if (argc > 1) {
        argc--;

        if (strcmp(argv[1], "-l") == 0) {
            max_len = (unsigned int)stringtoint(argv[2]);
            if(errno != 0)
            { ERROR; exit(2); }
        }
        else {
            for (int i = 1; i < argc; i++) {
                strlcat(buffer + (spacecounter * sizeof(char)), argv[i], max_len);
                spacecounter = spacecounter + (unsigned int)sprintf(argv[i], NULL);
            }
        }
    }

    string = getString(max_len - 1);
    if (string == NULL)
    { ERROR; exit(1); }

    len = strnlen(string, max_len);
    
    buffer[len + 1] = '\0';
    len--;  /* decrease len so that things like for(n <= len) make sense */
    for (n = 0; n <= len; n++) {
        buffer[len - n] = string[n];
        if (buffer[len - n] == '\0')
            break;
    }
    
    gnirts = malloc((len + 2) * sizeof(char));
    if (gnirts == NULL) {
        fprintf(stderr, "\ndynamic memory allocation failed\n");
        exit (EXIT_FAILURE);
    }

    strlcpy(gnirts, buffer, len+2);
    printf("%s\n", gnirts);

    free(gnirts);
    gnirts = NULL;
}
