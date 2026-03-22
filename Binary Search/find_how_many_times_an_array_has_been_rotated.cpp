#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRotations(vector<int> &arr)
    {

        int low = 0;
        int high = arr.size() - 1;

        while (low < high)
        {

            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[high])
            {
                low = mid + 1;
            }
            else
            {

                high = mid;
            }
        }

        return low;
    }
};

int main()
{
    Solution sol;
    
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int rotations = sol.findRotations(arr);

    cout << rotations << endl;
    return 0;
}