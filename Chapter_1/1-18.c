#include <stdio.h>
// Write a program to remove trailing blanks and tabs from each line of input. Delete entirely blank lines.
#define MAXLINE 1000

int get_line(char line[], int maxline, char newarray[]);
void copy(char to[], char from[]);
void stripline(char oldline[], char newline[], int i);

int main(void)
{
    int len;
    char line[MAXLINE];

    int maxlen;
    char cleanedline[MAXLINE];

    maxlen = 0;
    while ((len = get_line(line, MAXLINE, cleanedline)) > 0)
    {
        if (len > 1) {
            printf("word: %s", cleanedline);
        }
        

        //printf("line_length: %d", len);
        //printf(": %s", line);
    }

    return 0;
}

void clean(char oldline[], char newline[], int lenoldline) {
    int i = 0;
    
    if (lenoldline == 0) {
        return;
    }
    while (oldline[lenoldline] == ' ' || oldline[lenoldline] == '\t') {
        lenoldline--;
    }
    while (i < lenoldline) {
        newline[i] = oldline[i];
        i++;
    }
    newline[i] = '\n';
    newline[i + 1] = '\0';
}

int get_line(char s[], int maxline, char newarray[])
{
    int c, i;
    

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        clean(s, newarray, i);
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