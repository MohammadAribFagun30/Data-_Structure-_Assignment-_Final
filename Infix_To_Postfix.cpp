#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char value) {
        arr[++top] = value;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// check operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack st;
    int j = 0;

    // Step 1: push '(' and add ')' at end
    st.push('(');
    int n = strlen(infix);
    infix[n] = ')';
    infix[n + 1] = '\0';

    // Step 2: scan left to right
    for (int i = 0; i < strlen(infix); i++) {

        char ch = infix[i];

        // Step 3: operand → add to postfix
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[j++] = ch;
        }

        // Step 4: left parenthesis
        else if (ch == '(') {
            st.push(ch);
        }

        // Step 5: operator
        else if (isOperator(ch)) {

            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix[j++] = st.pop();
            }

            st.push(ch);
        }

        // Step 6: right parenthesis
        else if (ch == ')') {

            while (!st.isEmpty() && st.peek() != '(') {
                postfix[j++] = st.pop();
            }

            st.pop(); // remove '('
        }
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter Infix Expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}