#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();

        // bubble sort (brute force) --> accepted but has a TC of O(n ^ 2)
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = 0; j < n - i - 1; j++) {
        //         if (nums[j] > nums[j + 1]) {
        //             swap(nums[j], nums[j + 1])
        //         }
        //     }
        // }

        // Optimised --> DNF (3 pointer approach)
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}