#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (m.find(sum - k) != m.end())
            {
                count += m[sum - k];
            }

            m[sum]++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;

    cout << sol.subarraySum(arr, k) << endl;

    return 0;
}