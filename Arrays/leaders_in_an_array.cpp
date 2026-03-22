#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> ans;

        if (nums.empty())
        {
            return ans;
        }

        int max = nums[nums.size() - 1];
        ans.push_back(nums[nums.size() - 1]);

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > max)
            {
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {16, 17, 4, 3, 5, 2};

    vector<int> ans = sol.leaders(nums);

    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}