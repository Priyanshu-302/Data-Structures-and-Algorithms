#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int new_reach = 0, n = nums.size(), max_reach = 0, jumps = 0;

        for (int i = 0; i < n - 1; i++)
        {
            max_reach = max(max_reach, i + nums[i]);

            if (i == new_reach)
            {
                jumps++;
                new_reach = max_reach;
            }

            if (new_reach >= n - 1)
                break;
        }

        return jumps;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    int result = sol.jump(nums);
    cout << "Minimum number of jumps: " << result << endl;

    return 0;
}