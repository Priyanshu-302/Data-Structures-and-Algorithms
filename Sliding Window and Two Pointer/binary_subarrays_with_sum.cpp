#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int atMost(vector<int> &nums, int goal)
    {
        int cnt = 0;
        int l = 0, r = 0, sum = 0;

        while (r < nums.size())
        {
            if (goal < 0)
                return 0;
            sum += nums[r];

            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << sol.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}