#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        // Brute Force --> Linear Search - O(n)
        // int mini = 5001;
        // for (int i = 0; i < n; i++) {
        //     if (mini > nums[i]) mini = nums[i];
        // }

        // return mini;

        // Optimized --> Binary Search - O(log n)
        int low = 0, high = n - 1, ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {3, 4, 5, 1, 2};
    int ans = obj.findMin(nums);
    cout << ans << endl;
    return 0;
}