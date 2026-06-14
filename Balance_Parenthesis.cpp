#include <iostream>
#include <string>
using namespace std;

bool isBalanced(string s)
{
    char stack[1000];
    int top = -1;

    for (char c : s)
    {
        // Opening brackets
        if (c == '(' || c == '{' || c == '[')
        {
            stack[++top] = c;
        }

        // Closing brackets
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
                return false;

            char temp = stack[top--];

            if ((c == ')' && temp != '(') ||
                (c == '}' && temp != '{') ||
                (c == ']' && temp != '['))
            {
                return false;
            }
        }
    }

    return (top == -1);
}

int main()
{
    string s = "[()()]{}";

    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}