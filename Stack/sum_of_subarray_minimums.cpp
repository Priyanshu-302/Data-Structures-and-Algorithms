#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7;

private:
    vector<int> pse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> left = pse(arr);
        vector<int> right = nse(arr);
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum = (sum + (long long)arr[i] * (i - left[i]) % mod * (right[i] - i)) % mod;
        }

        return (int)sum;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {3, 1, 2, 4};

    cout << sol.sumSubarrayMins(arr) << endl;

    return 0;
}