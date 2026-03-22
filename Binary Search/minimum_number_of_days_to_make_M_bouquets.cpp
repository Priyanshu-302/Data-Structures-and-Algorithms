#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPossible(vector<int> &bloomDay, int currBloomDay, int m, int k)
    {
        int cnt = 0;
        int total_no_bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= currBloomDay)
            {
                cnt++;
            }
            else
            {
                total_no_bouquets += cnt / k;
                cnt = 0;
            }
        }

        total_no_bouquets += cnt / k;
        return total_no_bouquets >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k))
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
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    int ans = obj.minDays(bloomDay, m, k);
    cout << ans << endl;
    return 0;
}