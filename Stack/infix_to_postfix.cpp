#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";

    for (char ch : s)
    {
        if (ch == '(')
            st.push(ch);
        else if (isalnum(ch))
        {
            ans += ch;
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(ch))
        {
            while (!st.empty() && precedence(ch) <= precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s = "a+b*(c^d-e)";
    cout << infixToPostfix(s) << endl;
    return 0;
}