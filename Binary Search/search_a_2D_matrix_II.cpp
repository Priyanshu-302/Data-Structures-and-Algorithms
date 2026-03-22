#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool binarySearch(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            if (binarySearch(matrix[i], target))
                return true;
        }

        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    bool ans = obj.searchMatrix(matrix, target);
    cout << ans << endl;
    return 0;
}