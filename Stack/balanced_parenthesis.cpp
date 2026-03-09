#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    stack<int> st;

public:
    bool isValid(string s)
    {
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty() || (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution sol;

    vector<string> tests = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",
        "(((",
        "{[()()]}"};

    for (const string &t : tests)
    {
        cout << "\"" << t << "\" → " << (sol.isValid(t) ? "Valid" : "Invalid") << "\n";
    }

    return 0;
}