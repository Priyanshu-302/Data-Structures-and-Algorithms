#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n = g.size(), m = s.size();
        int i = 0, j = 0, max_content = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (i < n && j < m)
        {
            if (s[j] >= g[i])
            {
                max_content++;
                i++;
            }
            j++;
        }

        return max_content;
    }
};

int main()
{
    Solution sol;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1, 2};

    int result = sol.findContentChildren(g, s);
    cout << "Maximum Content Children: " << result << endl;

    return 0;
}