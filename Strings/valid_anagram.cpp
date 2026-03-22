#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<char, int> mpp;
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            mpp[s[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            mpp[t[i]]--;
        }

        for (int i = 0; i < n; i++)
        {
            if (mpp[t[i]] != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram", t = "nagaram";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}