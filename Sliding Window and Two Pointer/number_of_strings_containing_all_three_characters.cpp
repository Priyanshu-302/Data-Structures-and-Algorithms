#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        // Optimal Approach --> TC - O(n)
        int n = s.size();
        int cntA = 0, cntB = 0, cntC = 0;
        int cnt = 0, left = 0;

        for (int right = 0; right < n; right++)
        {
            if (s[right] == 'a')
                cntA++;
            else if (s[right] == 'b')
                cntB++;
            else if (s[right] == 'c')
                cntC++;

            while (cntA > 0 && cntB > 0 && cntC > 0)
            {
                cnt += n - right;
                if (s[left] == 'a')
                    cntA--;
                else if (s[left] == 'b')
                    cntB--;
                else if (s[left] == 'c')
                    cntC--;

                left++;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution sol;

    cout << sol.numberOfSubstrings("abcabc") << endl;

    return 0;
}