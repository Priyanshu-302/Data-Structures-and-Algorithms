#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int freq[26] = {0};
        int l = 0, r = 0, max_freq = 0, max_len = INT_MIN;

        while (r < s.size())
        {
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);

            while ((r - l + 1) - max_freq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};

int main()
{
    Solution sol;

    cout << sol.characterReplacement("AABABBA", 1) << endl;

    return 0;
}