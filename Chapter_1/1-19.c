#include <stdio.h>
// Create a function to reverse the characters in a string. Reverse each line of input
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char to[],int size, char from[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    int maxlen;
    char reversedLine[MAXLINE];

    maxlen = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > 1) {  // Line is not empty
            reverse(line, len, reversedLine);
            printf("%s", reversedLine);
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

void reverse(char to[], int size, char from[])
{
    int i = 0;
    size = size - 2;
    while (size >= 0) {
        from[i] = to[size];
        size--;
        i++;
    }
    from[i] = '\n';
    from[i+1] = '\0';
}