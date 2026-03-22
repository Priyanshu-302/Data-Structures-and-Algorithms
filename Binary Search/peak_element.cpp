#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        // Brute Force
        // for (int i = 0; i < n; i++) {
        //     bool left = (i == 0) || (nums[i] >= nums[i - 1]);
        //     bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);

        //     if (left && right) return i;
        // }

        // return 0;

        // Optimised --> Binary Search
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if ((mid == 0 || nums[mid] >= nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] >= nums[mid + 1]))
            {
                return mid;
            }

            if (mid < n - 1 && nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return 0;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3, 1};
    int ans = obj.findPeakElement(nums);
    cout << ans << endl;
    return 0;
}