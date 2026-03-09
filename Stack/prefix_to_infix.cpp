#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToInfix(string s)
{
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        char ch = s[i];

        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else if (isOperator(ch))
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push("(" + t1 + ch + t2 + ")");
        }
    }

    return st.top();
}

int main()
{
    string s = "*+pq-mn";
    cout << prefixToInfix(s) << endl;
    return 0;
}