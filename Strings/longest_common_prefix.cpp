#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string common(string a, string b)
    {
        int n = min(a.size(), b.size());

        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                res += a[i];
            else
                break;
        }

        return res;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            prefix = common(prefix, strs[i]);
            if (prefix == "")
                break;
        }

        return prefix;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}