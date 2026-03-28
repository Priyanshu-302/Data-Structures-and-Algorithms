#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        int cnt = 0, last_end_time = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < last_end_time)
            {
                cnt++;
            }
            else
            {
                last_end_time = intervals[i][1];
            }
        }

        return cnt;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    int result = sol.eraseOverlapIntervals(intervals);
    cout << "Minimum number of intervals to remove: " << result << endl;

    return 0;
}