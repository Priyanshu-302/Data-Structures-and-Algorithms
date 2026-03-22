#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool applyBinarySearchWhereTargetIsPresent(vector<vector<int>> &matrix, int target, int targetPresentRow)
    {
        int n = matrix[0].size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[targetPresentRow][mid] == target)
                return true;
            else if (matrix[targetPresentRow][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target)
            {
                return applyBinarySearchWhereTargetIsPresent(matrix, target, mid);
            }
            else if (target < matrix[mid][0])
                high = mid - 1;
            else
                low = mid + 1;
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