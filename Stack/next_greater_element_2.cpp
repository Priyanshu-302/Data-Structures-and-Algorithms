#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    stack<int> st;

public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            // If the stack has smaller or equal element pop it off
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop();

            if (i < n && !st.empty())
                ans[i] = st.top();

            st.push(nums[i % n]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 1};

    vector<int> result = sol.nextGreaterElements(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << endl;
    return 0;
}