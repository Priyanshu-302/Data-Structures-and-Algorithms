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
    vector<int> nextLargerElement(vector<int> &arr)
    {
        vector<int> ans(arr.size(), -1);

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            // If the stack has smaller or equal element pop it off
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            // If the stack is empty, the nge is -1
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 3, 2, 4};

    vector<int> result = sol.nextLargerElement(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << endl;
    return 0;
}