#include <bits/stdc++.h>
using namespace std;

char st[100];
int top = -1;

void push(char ch)
{
    st[++top] = ch;
}

char pop()
{
    return st[top--];
}

char whoistop()
{
    return st[top];
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    string infix, postfix = "";

    cout << "Enter Infix : ";
    cin >> infix;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && whoistop() != '(')
            {
                postfix += pop();
            }
            pop(); // remove '('
        }
        else
        {
            while (top != -1 &&
                   whoistop() != '(' &&
                   precedence(whoistop()) >= precedence(ch))
            {
                postfix += pop();
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    cout << "Postfix : " << postfix << endl;

    return 0;
}