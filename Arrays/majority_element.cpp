#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // brute force -> TC O(nlogn)
        // sort(nums.begin(), nums.end());

        // return nums[nums.size() / 2];

        // optimized --> Boyer Moore's Voting Algorithm
        int cnt = 0;
        int ele;

        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                ele = nums[i];
                cnt = 1;
            }
            else if (ele == nums[i])
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << sol.majorityElement(nums) << endl;

    return 0;
}