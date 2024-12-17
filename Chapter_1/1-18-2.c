#include <stdio.h>
// Write a program to remove trailing blanks and tabs from each line of input. Delete entirely blank lines.
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
int stripline(char oldline[], int i);

int main(void)
{
    int len;
    char line[MAXLINE];
    int newlen;
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        // Print line if not blank
        if ((newlen = stripline(line, len)) > 0) {
            printf("length:%d, Stripped word: %s", newlen, line);
        }
    }

    return 0;
}

int stripline(char oldline[], int lenoldline) {
    if (lenoldline == 1) {
        return 0;
    }
    lenoldline--;   //Decrement len to find the char before '\n'
    lenoldline--;

    // Clean char array for blank space
    while (oldline[lenoldline] == ' ' || oldline[lenoldline] == '\t') {
        lenoldline--;
    }
    
    // Return 0 if string is empty after cleaning
    if (lenoldline == 0) {
        return 0;
    }
    // Add new line and terminator to complete new array
    lenoldline++;
    oldline[lenoldline] = '\n';
    oldline[lenoldline + 1] = '\0';
    
    
    return lenoldline;
    
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