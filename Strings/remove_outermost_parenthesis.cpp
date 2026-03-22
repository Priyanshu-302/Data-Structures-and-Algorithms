#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size(), cnt = 0;
        string res = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (cnt > 0)
                    res += s[i];
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt > 0)
                    res += s[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string s = "(()())(())";
    cout << sol.removeOuterParentheses(s) << endl;
    return 0;
}