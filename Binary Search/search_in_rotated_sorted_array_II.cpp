#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();

        // Brute Force --> Linear Search - O(n)
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == target) return true;
        // }

        // return false;

        // Optimized --> Binary Search - O(log n)
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            // If three are equal
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            // left sorted part search
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            // right sorted part search
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    bool ans = obj.search(nums, target);
    cout << ans << endl;
    return 0;
}