#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
private:
    unordered_map<char, int> mpp;

public:
    int longestKSubstr(string &s, int k)
    {
        int l = 0, r = 0, max_len = -1;

        while (r < s.size())
        {
            mpp[s[r]]++;

            while (mpp.size() > k)
            {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }

            if (mpp.size() == k)
                max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};

int main()
{
    Solution sol;

    string s = "aabacbebebe";
    cout << sol.longestKSubstr(s, 3) << endl;

    return 0;
}