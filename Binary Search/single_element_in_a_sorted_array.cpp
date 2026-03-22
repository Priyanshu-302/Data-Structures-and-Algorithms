#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        // Brute Force
        // for (int i = 0; i < n; i++) {
        //     if (i == 0 && nums[i] < nums[i + 1]) return nums[i];
        //     else if (i == n - 1 && nums[i] > nums[i - 1]) return nums[i];
        //     else if (nums[i] < nums[i + 1] && nums[i] > nums[i - 1]) return
        //     nums[i];
        // }

        // return -1;

        // Optimised --> Binary Search - O(log n)
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] < nums[mid + 1]))
                return nums[mid];

            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid - 1])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int ans = obj.singleNonDuplicate(nums);
    cout << ans << endl;
    return 0;
}