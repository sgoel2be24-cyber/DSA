#include <iostream>
#include <cctype>
#define MAX 100
using namespace std;

int top = -1;
int stack[MAX];

void push(int item)
{
    if (top >= MAX - 1)
    {
        cout << "stack overflow" << endl;
        return;
    }
    stack[top++] = item;
}
int pop()
{
    if (top < 0)
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    return stack[top--];
}
bool isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int main()
{
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    for (char c : expr)
    {

        if (isdigit(c))
        {
            push(c - '0');
        }
        else if (isoperator(c))
        {
            int a = pop();
            int b = pop();

            int result = 0;
            switch (c)
            {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                result = a / b;
                break;
            }
            push(result);
        }
    }
    cout << "result of expression : " << pop() << endl;
    return 0;
}
