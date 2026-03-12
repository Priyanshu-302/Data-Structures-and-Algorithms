#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res = "";
        stack<char> st;

        for (int i = 0; i < num.size(); i++)
        {
            while (!st.empty() && k > 0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // Remove remaining digits from the back (largest)
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        // Build result string
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        // Remove leading zeros (they're at the back before reverse)
        while (!res.empty() && res.back() == '0')
        {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res; // ✅ correct empty check, after reverse
    }
};

int main()
{
    Solution sol;

    string num = "1432219";
    int k = 3;

    cout << sol.removeKdigits(num, k) << endl;

    return 0;
}