#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0, platforms = 0, max_platforms = 0;
        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            else
            {
                platforms--;
                j++;
            }

            max_platforms = max(max_platforms, platforms);
        }

        return max_platforms;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    int result = sol.minPlatform(arr, dep);
    cout << "Minimum Number of Platforms: " << result << endl;

    return 0;
}