#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();

        vector<pair<double, pair<int, int>>> items;

        for (int i = 0; i < n; i++)
        {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }

        sort(items.begin(), items.end(), greater<>());
        double total = 0.0;

        for (int i = 0; i < n; i++)
        {
            int value = items[i].second.first;
            int weight = items[i].second.second;

            if (weight <= capacity)
            {
                total += value;
                capacity -= weight;
            }
            else
            {
                double fraction = (double)capacity / weight;
                total += fraction * value;
                capacity = 0;
            }
        }

        return round(total * 1e6) / 1e6;
    }
};

int main()
{
    Solution sol;

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    double result = sol.fractionalKnapsack(val, wt, capacity);
    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}