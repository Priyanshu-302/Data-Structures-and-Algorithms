#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // Better Approach --> using C++ STL
        // next_permutation(nums.begin(), nums.end());

        // Optimized approach --> longest prefix match (breakpoint)
        int n = nums.size();
        int break_pt_idx = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                break_pt_idx = i;
                break;
            }
        }

        if (break_pt_idx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > break_pt_idx; i--)
        {
            if (nums[i] > nums[break_pt_idx])
            {
                swap(nums[i], nums[break_pt_idx]);
                break;
            }
        }

        reverse(nums.begin() + break_pt_idx + 1, nums.end());
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3};

    sol.nextPermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}