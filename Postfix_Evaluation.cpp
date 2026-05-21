#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push function
    void push(int value) {
        arr[++top] = value;
    }

    // Pop function
    int pop() {
        return arr[top--];
    }

    // Get top element
    int peek() {
        return arr[top]; // Returns top element without removing.
    }
};

// Function to evaluate postfix expression
int evaluatePostfix(char exp[]) {
    Stack st;

    for (int i = 0; i < strlen(exp); i++) {

        // If operand
        if (isdigit(exp[i])) {
            st.push(exp[i] - '0');
        }

        // If operator
        else {
            int A = st.pop();
            int B = st.pop();

            switch (exp[i]) {
                case '+':
                    st.push(B + A);
                    break;

                case '-':
                    st.push(B - A);
                    break;

                case '*':
                    st.push(B * A);
                    break;

                case '/':
                    st.push(B / A);
                    break;
            }
        }
    }

    return st.peek();
}

int main() {
    char postfix[MAX];

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result << endl;

    return 0;
}