#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int atMost(vector<int> &nums, int k)
    {
        int cnt = 0;
        int l = 0, r = 0, odd_cnt = 0;

        while (r < nums.size())
        {
            if (nums[r] % 2 != 0)
                odd_cnt++;

            while (odd_cnt > k)
            {
                if (nums[l] % 2 != 0)
                {
                    odd_cnt--;
                }
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << sol.numberOfSubarrays(nums, k) << endl;

    return 0;
}