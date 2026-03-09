#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPrefix(string s)
{
    stack<char> st;
    string ans = "";

    reverse(s.begin(), s.end());

    for (char &ch : s)
    {
        if (ch == ')')
            ch = '(';
        else if (ch == '(')
            ch = ')';
    }

    for (char ch : s)
    {
        if (isalnum(ch))
        {
            ans += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
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
            if (ch == '^')
            {
                while (!st.empty() && precedence(ch) <= precedence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && precedence(ch) < precedence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "(a+b)*c-d+f";
    cout << infixToPrefix(s) << endl;
    return 0;
}