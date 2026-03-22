#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int total = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mpp[s[i]] < mpp[s[i + 1]])
                total -= mpp[s[i]];
            else
                total += mpp[s[i]];
        }

        return total;
    }
};

int main()
{
    Solution sol;
    string s = "MCMXCIV";
    cout << sol.romanToInt(s) << endl;
    return 0;
}