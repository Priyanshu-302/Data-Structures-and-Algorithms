#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
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

    vector<int> nge(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> pge(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    long long sumSubarrayMins(vector<int> &arr)
    {
        vector<int> left = pse(arr);
        vector<int> right = nse(arr);
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum = (sum + (long long)arr[i] * (i - left[i]) * (right[i] - i));
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left = pge(arr);
        vector<int> right = nge(arr);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long l = i - left[i];
            long long r = right[i] - i;
            sum += (long long)arr[i] * l * r;
        }
        return sum;
    }

public:
    long long subArrayRanges(vector<int> &nums)
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3};

    cout << sol.subArrayRanges(nums) << endl;

    return 0;
}