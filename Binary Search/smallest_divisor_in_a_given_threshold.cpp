#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int isPossible(vector<int> &nums, int currDivisor)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / currDivisor);
        }

        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int currThreshold = isPossible(nums, mid);
            if (currThreshold <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    int ans = obj.smallestDivisor(nums, threshold);
    cout << ans << endl;
    return 0;
}