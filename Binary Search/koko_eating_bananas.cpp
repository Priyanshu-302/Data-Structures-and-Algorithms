#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long calculateBananaEatingSpeed(vector<int> &piles, int curr_speed)
    {
        long long total_hours = 0;

        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            total_hours += ceil((double)piles[i] / (double)curr_speed);
        }

        return total_hours;
    }

public:
    int minEatingSpeed(vector<int> &piles, int max_speed)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long curr_speed = calculateBananaEatingSpeed(piles, mid);

            if (curr_speed <= max_speed)
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
    vector<int> piles = {3, 6, 7, 11};
    int max_speed = 8;
    int ans = obj.minEatingSpeed(piles, max_speed);
    cout << ans << endl;
    return 0;
}