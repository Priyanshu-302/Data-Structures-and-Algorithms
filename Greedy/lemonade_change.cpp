#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();

        int five = 0, ten = 0;
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10)
            {
                ten++;
                if (five > 0)
                    five--;
                else
                    return false;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    vector<int> bills = {5, 5, 5, 10, 20};

    bool result = sol.lemonadeChange(bills);
    cout << "Can lemonade be served? " << (result ? "Yes" : "No") << endl;

    return 0;
}