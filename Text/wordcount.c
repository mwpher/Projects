/*-----------------------------------------------------------------------------
 *
 * wordcount
 * Count number of words in a given string
 * 
 * Author: Matthew Pherigo
 * Date Created: 2015-04-02
 *
 *-----------------------------------------------------------------------------*/

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <matt.h>
#include <regex.h>

char* get_str(char* s, int argc, const char *argv[]);
void count_words(char* regex_text);

int main(int argc, const char *argv[]) {
    char* s = NULL;
    if (argc == 2) {
        fprintf(stderr, "need more arguments to count!\n");
        exit(EXIT_FAILURE);
    }

    s = get_str(s, argc, argv);

    printf("%s\n", s);

    count_words(s);

    free(s);
    s = NULL;
    return EXIT_SUCCESS;
}

char* get_str(char* s, int argc, const char *argv[])
{
    unsigned int len = 1; // init to one for NULL
    unsigned int i = 0;
    if (argc <= 1) {
        s = getString(255);
    }
    else {
        for (i = 1; i < (unsigned int)argc; i++) {
            len = len + strlen(argv[i]) + 1;
        }
        s = calloc((size_t)(len), sizeof(char));
        if(s == NULL ) {
            fprintf(stderr, "ndynamic memory allocation failedn" );
            exit(EXIT_FAILURE);
        }

        for (i = 1; i < (unsigned int)argc; i++) {
            strlcat(s, argv[i], len);
            if (i < (unsigned int) argc - 1) {
                strlcat(s, " ", len);
            }
        }
    }
    return s;
}

void count_words(char* to_match) {
    const char* regex_text = " ";
    regex_t regex;
    int reti;
    /* "P" is a pointer into the string which points to the end of the
       previous match. */
    const char * p = to_match;
    /* "N_matches" is the maximum number of matches allowed. */
    const int n_matches = 10;
    /* "M" contains the matches found. */
    regmatch_t m[n_matches];


    /* Compile regular expression */
    reti = regcomp(&regex, regex_text, 0);
    if(reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }

    /* Execute regular expression */
    while (1) {
        int i = 0;
        int nomatch = regexec(&regex, p, n_matches, m, 0);
        if (nomatch) {
            printf ("No more matches.\n");
            break;
        }
        for (i = 0; i < n_matches; i++) {
            long long start;
            long long finish;
            if (m[i].rm_so == -1) {
                break;
            }
            start = m[i].rm_so + (p - to_match);
            finish = m[i].rm_eo + (p - to_match);
            if (i == 0) {
                printf ("$& is ");
            }
            else {
                printf ("$%d is ", i);
            }
            printf ("'%.*s' (bytes %d:%d)\n", (int)(finish - start),
                    to_match + start, (int)start, (int)finish);
        }
        p += m[0].rm_eo;
    }

    regfree(&regex);
}
