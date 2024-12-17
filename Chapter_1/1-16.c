#include <stdio.h>
// Write a program to print the length of lines and as much of the text as possible
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    int maxlen;
    char maxline[MAXLINE];

    maxlen = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > maxlen)
        {
            maxlen = len;
            copy(maxline, line);
        }

        printf("line_length: %d", len);
        printf(": %s", line);
    }

    if (maxlen > 0)
    {
        printf("%s", maxline);
    }

    return 0;
}

int get_line(char s[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}