#include <stdio.h>
// Fold long input lines into shorter lines after the last non-blank character that occurs before the n-th column of input
#define MAXLINE 1000

int get_line(char line[], int maxline);
void split_input(char line[], int len);
int nthColumn = 10;

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
            split_input(line, len);
        }
    }
    return 0;
}

void split_input(char line[], int len) {
    int i = 0;
    int j;
    char tmp;

    while (i < len) {
        if ((i != 0) && (i % nthColumn == 0)) {
            if (line[i] != ' ' || line[i] != '\t') {
                if (line[i+1] != ' ' || line[i+1] != '\t') {
                    printf("%c-\n", line[i]);
                    
                }
                else {
                    printf("%c", line[i]);
                }
            }
            else {
                j = i;
                while (line[i] == ' ' || line[i] == '\t') {
                    i--;
                }
                i = j;
                printf("\n");
            }
        }
        else {
            printf("%c", line[i]);
        }
        i++;
    }   
}

int get_line(char s[], int maxline)
{
    int c, i, j;
    

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    
    return i;
}


