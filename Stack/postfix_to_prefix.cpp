#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToPrefix(string postfix)
{
    stack<string> st;

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            // Push operand as string
            st.push(string(1, c));
        }
        else if (isOperator(c))
        {
            // Pop two operands
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            // Form prefix: operator + op1 + op2
            string expr = c + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string postfix = "ab-de+f*/";
    cout << postfixToPrefix(postfix) << endl;
    return 0;
}