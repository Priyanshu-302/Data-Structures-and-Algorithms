#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isAllPackageShippable(vector<int> &weights, int currMaxCapacity, int days)
    {
        int currDays = 1, currCapacity = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (currCapacity + weights[i] > currMaxCapacity)
            {
                currCapacity = 0;
                currDays++;
            }
            currCapacity += weights[i];
        }

        return currDays <= days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0), ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isAllPackageShippable(weights, mid, days))
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
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int ans = obj.shipWithinDays(weights, days);
    cout << ans << endl;
    return 0;
}