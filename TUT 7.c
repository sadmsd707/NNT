#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 80
struct stack
{
    double s[SIZE];
    int top;
} st;
void push(double val);
double pop(void);
double post(char exp[]);
int main(void)
{
    char exp[SIZE];
    int len;
    double result;
    printf("\nEnter a postfix expression: ");
    scanf("%79s", exp);
    len = strlen(exp);
    exp[len] = '$';
    exp[len + 1] = '\0';
    result = post(exp);
    printf("\nThe value of the expression is %f\n", result);
    return 0;
}
double post(char exp[])
{
    char ch;
    double result, val, op1, op2;
    int i = 0;
    st.top = -1;
    ch = exp[i];
    while (ch != '$')
    {
        if (ch >= '0' && ch <= '9')
        {
            val = ch - '0';
            push(val);
        }

        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '^')
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
            }
            push(result);
        }
        i++;
        ch = exp[i];
    }
    result = pop();
    return result;
}
void push(double val)
{
    if (st.top >= SIZE - 1)
    {
        printf("\nStack full");
        return;
    }
    st.top++;
    st.s[st.top] = val;
}
double pop(void)
{
    double val;
    if (st.top == -1)
    {
        printf("\nStack is empty");
        return 0;
    }
    val = st.s[st.top];
    st.top--;
    return val;
}
