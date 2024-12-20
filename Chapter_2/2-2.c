#include <stdio.h>
#define MAXLINE 1000

// for (i=0; i<lim-1 && (c=getchar()) != '\n && c != EOF; ++i)
// Recreate above loop without using && or ||

int get_line(char line[], int maxline);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%s\n", line);
    }
}



int get_line(char s[], int maxline)
{
    int c, i;
    i = 0;

    /*
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }*/
    while (i < maxline - 1) {
        if ((c = getchar()) != EOF) {
            if (c != '\n') {
                s[i] = c;
                i++;
            }
            else {
                s[i] = c;
                ++i;
                s[i] = '\0';
                return i;
            }
        }
        else {
            return EOF;
        }
        
    }


    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}