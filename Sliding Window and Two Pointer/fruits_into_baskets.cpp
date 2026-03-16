#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    unordered_map<int, int> mpp;

public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int l = 0, r = 0, max_len = INT_MIN;

        while (r < n)
        {
            mpp[fruits[r]]++;

            while (mpp.size() > 2)
            {
                mpp[fruits[l]]--;

                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);

                l++;
            }

            max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};

int main()
{
    Solution sol;

    vector<int> fruits = {1, 2, 3, 2, 2};

    cout << sol.totalFruit(fruits) << endl;

    return 0;
}