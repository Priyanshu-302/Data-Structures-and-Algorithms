#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    stack<int> st;

public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();

        for (int i = 0; i < n; i++)
        {
            bool blast = false;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0)
            {
                if (abs(st.top()) < abs(asteroids[i]))
                {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(asteroids[i]))
                {
                    st.pop();
                }
                blast = true;
                break;
            }

            if (!blast)
                st.push(asteroids[i]);
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> asteroids = {5, 10, -5};

    vector<int> result = sol.asteroidCollision(asteroids);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << endl;
    return 0;
}