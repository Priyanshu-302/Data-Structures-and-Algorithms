#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int buy = prices[0];
        int max_profit = 0;

        for (int i = 1; i < n; i++)
        {
            if (prices[i] > buy)
            {
                max_profit = max(max_profit, prices[i] - buy);
            }
            else
            {
                buy = prices[i];
            }
        }

        return max_profit;
    }
};

int main()
{
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << sol.maxProfit(prices) << endl;

    return 0;
}