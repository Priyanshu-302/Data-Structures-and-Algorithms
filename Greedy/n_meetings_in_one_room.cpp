#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();

        vector<pair<int, int>> meetings(n);

        for (int i = 0; i < n; i++)
        {
            meetings[i] = {end[i], start[i]};
        }

        sort(meetings.begin(), meetings.end());

        int curr_end_time = meetings[0].first;
        ;
        int count = 1;

        for (int i = 0; i < n; i++)
        {
            if (meetings[i].second > curr_end_time)
            {
                count++;
                curr_end_time = meetings[i].first;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    int result = sol.maxMeetings(start, end);
    cout << "Maximum Meetings: " << result << endl;

    return 0;
}