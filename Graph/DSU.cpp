#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    int n;
    vector<int> parent, rank;

    DSU(int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB)
            return;

        if (rank[parA] == rank[parB])
        {
            parent[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        {
            parent[parB] = parA;
        }
        else
        {
            parent[parA] = parB;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return par[x] = find(parent[x]); // Path Compression
    }
};

int main()
{
    DSU dsu(6);

    dsu.unionByRank(0, 1);
    dsu.unionByRank(1, 2);
    dsu.unionByRank(3, 4);
    dsu.unionByRank(0, 3);

    cout << dsu.find(2) << endl;

    return 0;
}