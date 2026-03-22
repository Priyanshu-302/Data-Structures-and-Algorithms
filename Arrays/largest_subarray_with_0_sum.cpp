#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();

        // Brute Force --> TC - O (n ^ 2)
        // int maxi = 0;

        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += arr[j];

        //         if (sum == 0) {
        //             maxi = max(maxi, j - i + 1);
        //         }
        //     }
        // }

        // return maxi;

        // Optimal --> Prefix Sum + Hashmap
        int maxi = 0;
        int prefix_sum = 0;

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            prefix_sum += arr[i];

            if (prefix_sum == 0)
                maxi = i + 1;

            if (mpp.find(prefix_sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[prefix_sum]);
            }
            else
            {
                mpp[prefix_sum] = i;
            }
        }

        return maxi;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << sol.maxLength(arr) << endl;

    return 0;
}