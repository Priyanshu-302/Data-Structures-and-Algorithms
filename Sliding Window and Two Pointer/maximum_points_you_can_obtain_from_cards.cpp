#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int winSize = cardPoints.size() - k;
        int windowSum = 0;

        // Make the first window
        for (int i = 0; i < winSize; i++)
        {
            windowSum += cardPoints[i];
        }

        int totalPoints = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        // Assume it is the smallest one
        int minWindowSum = windowSum;

        // Traverse through the rest of the window
        for (int i = winSize; i < cardPoints.size(); i++)
        {
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i - winSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalPoints - minWindowSum;
    }
};

int main()
{
    Solution sol;

    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << sol.maxScore(cardPoints, k) << endl;

    return 0;
}