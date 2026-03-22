#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, int> freq;
public:
    // Function to count subarrays with given XOR
    int countSubarrays(vector<int> &A, int k)
    {
        freq[0] = 1;

        int prefixXor = 0;
        int count = 0;

        for (int num : A)
        {
            prefixXor ^= num;

            int target = prefixXor ^ k;

            if (freq.find(target) != freq.end())
            {
                count += freq[target];
            }

            freq[prefixXor]++;
        }
        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> A = {4, 2, 2, 6, 4};
    int k = 6;

    cout << sol.countSubarrays(A, k) << endl;

    return 0;
}