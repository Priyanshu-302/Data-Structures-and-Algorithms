#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        string st = s + s;

        return st.find(goal) != string::npos;
    }
};

int main()
{
    Solution sol;
    string s = "abcde", goal = "cdeab";
    cout << sol.rotateString(s, goal) << endl;
    return 0;
}