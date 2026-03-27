#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;

        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.emplace_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        ans.emplace_back(newInterval);

        while (i < n)
        {
            ans.emplace_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = sol.insert(intervals, newInterval);
    cout << "Intervals after insertion: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
    }
    cout << endl;

    return 0;
}