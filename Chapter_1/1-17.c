#include <stdio.h>
// Print all input lines that are longer than 80
#define MAXLINE 1000
#define MIN 80

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    char line[MAXLINE];
    char maxline[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len >= MIN)
        {
            printf("line_length: %d", len);
            printf(": %s", line);
        }        
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
