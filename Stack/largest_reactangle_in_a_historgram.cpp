#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> findPSE(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNSE(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}