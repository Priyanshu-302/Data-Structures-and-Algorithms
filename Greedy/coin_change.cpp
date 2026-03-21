#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* It is partially accepted, optimal approach requires DP */

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        sort(coins.begin(), coins.end(), greater<>());

        int coin = 0;
        for (int i = 0; i < n; i++)
        {
            while (amount >= coins[i])
            {
                coin++;
                amount -= coins[i];
            }
        }

        return amount == 0 ? coin : -1;
    }
};

int main()
{
    Solution sol;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);
    cout << "Minimum number of coins: " << result << endl;

    return 0;
}