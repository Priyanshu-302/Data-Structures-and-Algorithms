#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();

        int min_range = 0, max_range = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                min_range++;
                max_range++;
            }
            else if (s[i] == ')')
            {
                min_range--;
                max_range--;
            }
            else
            {
                min_range--;
                max_range++;
            }

            if (min_range < 0)
                min_range = 0;
            if (max_range < 0)
                return false;
        }

        return (min_range == 0) ? true : false;
    }
};

int main()
{
    Solution sol;

    string s = "(*))";

    bool result = sol.checkValidString(s);
    cout << "Valid String: " << (result ? "Yes" : "No") << endl;

    return 0;
}