#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0, zero = 0, max_len = INT_MIN;

        while (r < n)
        {
            // If it is a zero, increase the count no matter what
            if (nums[r] == 0)
                zero++;

            // If zero > k, decrease zero until it becomes == k and shrink the window
            while (zero > k)
            {
                if (nums[l] == 0)
                    zero--;
                l++;
            }

            // If zero <= k, take the max length out
            if (zero <= k)
            {
                max_len = max(max_len, r - l + 1);
            }

            r++;
        }

        return max_len;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << sol.longestOnes(nums, k) << endl;

    return 0;
}