#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj; // dynamic adjacency list
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        int src = 0;
        vector<bool> vis(V, false);

        dfsHelper(src, vis);
        cout << endl;
    }
};

int main() {
    Graph g(10);

    g.addEdge(0, 3);
    g.addEdge(3, 9);
    g.addEdge(3, 5);
    g.addEdge(9, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    cout << "DFS: " << endl;
    g.dfs();
    return 0;
}