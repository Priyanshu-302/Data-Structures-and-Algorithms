#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // Assume each cell is a potential celebrity except the diagonal
        int potential_celebrity = 0;
        for (int i = 1; i < n; i++)
        {
            if (mat[potential_celebrity][i] == 1)
            {
                // Cannot be a celebrity
                potential_celebrity = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            // Skip diagonal
            if (i == potential_celebrity)
                continue;

            if (mat[potential_celebrity][i] == 1 || mat[i][potential_celebrity] == 0)
            {
                // It is a not celebrity
                return -1;
            }
        }

        int celebrity = potential_celebrity;
        return celebrity;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {1, 1, 1}};

    cout << sol.celebrity(mat) << endl;

    return 0;
}