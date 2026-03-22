#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.size();

        int depth = 0, maxDepth = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (s[i] == ')')
                depth--;
        }

        return maxDepth;
    }
};

int main()
{
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << sol.maxDepth(s) << endl;
    return 0;
}