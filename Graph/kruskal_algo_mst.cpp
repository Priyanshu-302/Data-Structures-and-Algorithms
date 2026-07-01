class Solution
{
private:
    vector<int> parent, rank;

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionByRank(int x, int y)
    {
        int parX = find(x);
        int parY = find(y);

        if (parX == parY)
            return; // cycle

        if (rank[parX] < rank[parY])
        {
            parent[parX] = parY;
        }
        else if (rank[parX] > rank[parY])
        {
            parent[parY] = parX;
        }
        else
        {
            parent[parY] = parX;
            rank[parX]++;
        }
    }

public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        vector<vector<int>> edgeList;

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            edgeList.push_back({wt, u, v});
        }

        sort(edgeList.begin(), edgeList.end());

        int mstWeight = 0;

        for (auto &edge : edgeList)
        {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (find(u) != find(v))
            { // no cycle
                mstWeight += wt;
                unionByRank(u, v);
            }
        }

        return mstWeight;
    }
};