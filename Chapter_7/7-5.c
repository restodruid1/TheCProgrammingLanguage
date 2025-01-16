#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFFSIZE 100
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
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

        case 'm':   // Math functionality
            if (strcmp(s, "pow") == 0) {
                push(pow(pop(), pop()));
            }
            else if (strcmp(s, "exp") == 0) {
                push(exp(pop()));
            }
            else if (strcmp(s, "sin") == 0) {
                push(sin(pop()));
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


int getop(char s[])
{
    int c;
    int i;

    scanf("%c", &c);

    while (c == ' ')
        scanf("%c", &c);    //Scan input until character is found
    
    i = 0;
    if (isdigit(c)) {   // Handle digits of all lengths and decimals
        s[i++] = c;
        scanf("%c", &c);
        while (c == '.' || isdigit(c)) {
            s[i++] = c;
            scanf("%c", &c);
        }
        s[i] = '\0';
        return NUMBER;
    }
    else if (!isdigit(c) && c != EOF || c != '\n') {    // Is an operator
        s[0] = c;
        s[1] = '\0';
        return c;
    }
    else {
        return EOF;
    }
    
}