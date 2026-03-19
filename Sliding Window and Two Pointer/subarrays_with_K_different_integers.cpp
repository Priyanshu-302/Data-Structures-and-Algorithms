#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    int atMost(vector<int> &nums, int k)
    {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (r < nums.size())
        {
            mpp[nums[r]]++;

            while (mpp.size() > k)
            {
                mpp[nums[l]]--;

                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            if (mpp.size() <= k)
                cnt += r - l + 1;
            r++;
        }

        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << sol.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}