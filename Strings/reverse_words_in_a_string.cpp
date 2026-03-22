#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();

        reverse(s.begin(), s.end());
        string res;

        for (int i = 0; i < n; i++)
        {
            string word = "";
            while (i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.size() > 0)
            {
                res += " " + word;
            }
        }

        return res.substr(1);
    }
};

int main()
{
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s) << endl;
    return 0;
}