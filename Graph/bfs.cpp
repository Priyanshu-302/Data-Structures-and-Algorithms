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

    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
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

    cout << "BFS: " << endl;
    g.bfs();
    return 0;
}