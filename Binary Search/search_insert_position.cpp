#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();

        // Brute Force --> TC - O(n)
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == target)
        //         return i;
        // }

        // for (int i = 0; i < n; i++) {
        //     if (target < nums[i])
        //         return i;
        // }

        // return n;

        // Optimised --> Binary Search - TC - O(log n)
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution obj;
    int ans = obj.searchInsert(nums, target);
    cout << ans << endl;

    return 0;
}