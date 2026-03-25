#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int max_reach = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > max_reach)
                break;

            max_reach = max(max_reach, i + nums[i]);

            if (max_reach >= n - 1)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    bool result = sol.canJump(nums);
    cout << "Can jump to the last index? " << (result ? "Yes" : "No") << endl;

    return 0;
}