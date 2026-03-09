#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToInfix(string s)
{
    stack<string> st;

    for (char ch : s)
    {
        if (isalnum(ch))
            st.push(string(1, ch));
        else if (isOperator(ch))
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push("(" + t2 + ch + t1 + ")");
        }
    }

    return st.top();
}

int main()
{
    string s = "ab-de+f*/";
    cout << postfixToInfix(s) << endl;
    return 0;
}