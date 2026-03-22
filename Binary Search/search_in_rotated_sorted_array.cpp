#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int tar)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == tar)
                return mid;

            if (arr[low] <= arr[mid])
            {
                if (arr[low] <= tar && arr[mid] >= tar)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (arr[mid] <= tar && arr[high] >= tar)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int tar = 0;
    int ans = sol.search(arr, tar);
    cout << ans << endl;
    return 0;
}