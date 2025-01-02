#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFFSIZE 100
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int sp = 0; // so main can see and print from top of stack
double val[MAXVAL];

int main(void)
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            op2 = pop();

            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("Error: zero divisor.\n");
            }

            break;

        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int)pop() % (int)op2);
            }
            else {
                printf("Error: zero divisor.\n");
            }
            break;

        case 't':   // Print top stack val
            printf("Top of stack: %g\n", val[sp]);
            break;

        case 'd':   // Duplicate top stack val
            op2 = pop();
            val[sp++] = op2;
            val[sp++] = op2;
            break;

        case 's':   // Swap top 2 stack vals
            op1 = pop();
            op2 = pop();
            val[sp++] = op1;
            val[sp++] = op2;
            break;

        case 'c': // Clear stack
            sp = 0;
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: unknown command %s.\n", s);
            break;
        }
    }

    return 0;
}


//int sp = 0;
//double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: stack full, can't push %g.\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("Error: stack empty.\n");
        return 0.0;
    }
}

int bufp = 0;
char buf[BUFFSIZE];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getop(char s[])
{
    int i, c;
    int tmp;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        if (c == '-') {
            tmp = c;        // Store c
            c = getch();    // get next char
            
            if (!isdigit(c)) {  // c is a blank space e.g., 4 - 2 and not 4 -2 
                //printf("%c : ", c);
                ungetch(c);     // Undo getchar
                return tmp;
            }
            else {
                ungetch(c);     // Undo getchar
            }
        }
        else {
            return c;       // c is an operator
        }
        
    }
    i = 0;
    if (c == '-') { // This is a negative number
        s[i++] = c;
        c = getch();
    }
    
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) { //add c to s while c is a digit
            ;
        }
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}