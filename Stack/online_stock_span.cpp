#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main()
{
    StockSpanner stockSpanner;
    cout << stockSpanner.next(100) << " ";
    cout << stockSpanner.next(80) << " ";
    cout << stockSpanner.next(60) << " ";
    cout << stockSpanner.next(70) << " ";
    cout << stockSpanner.next(60) << " ";
    cout << stockSpanner.next(75) << " ";
    cout << stockSpanner.next(85) << " ";
    return 0;
}