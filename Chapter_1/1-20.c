#include <stdio.h>
// Replace tabs with proper amount of blank spaces
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char to[],int size, char from[]);

char tab = ' ';

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
            printf("%s", line);
        }
    }
    return 0;
}

int get_line(char s[], int maxline)
{
    int c, i, j;
    

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c == '\t') {
            if (i + 3 < maxline - 1) {  // Ensure we fit within maxline size
                for (j = 0; j < 4; j++) {   // Add 4 blank spaces
                    s[i + j] = tab;
                }
                i = i + 3;  // Increment i to account for blank spaces added
            }
        }
        else {
            s[i] = c;
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