#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToPostfix(string prefix)
{
    stack<string> st;

    // Traverse prefix from RIGHT to LEFT
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isalnum(c))
        {
            // Push operand as string
            st.push(string(1, c));
        }
        else if (isOperator(c))
        {
            // Pop two operands
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            // Form postfix: op1 + op2 + operator
            string expr = op1 + op2 + c;
            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string prefix = "/-ab*+def";
    cout << prefixToPostfix(prefix) << endl;
    return 0;
}