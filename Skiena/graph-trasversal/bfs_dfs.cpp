#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Graph Traversal: BFS & DFS (with cycle detection for directed graphs)
- Adjacency list representation
- BFS from a start node
- DFS from a start node
- Cycle detection in directed graphs using recursion stack
- Handles both directed and undirected graphs (toggle flag in main)
*/

struct Graph {
    int n;                      // Number of vertices
    bool undirected;             // Graph type
    vector<vector<int>> adj;     // Adjacency list

    Graph(int n, bool undirected): n(n), undirected(undirected), adj(n) {}

    // Add an edge from u to v. If undirected, also add v->u.
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (undirected) adj[v].push_back(u);
    }
};

// BFS traversal from start node s
vector<int> bfs(const Graph& g, int s) {
    vector<int> order;           // Order in which nodes are visited
    vector<int> dist(g.n, -1);   // Distance from start node
    queue<int> q;

    dist[s] = 0;                 // Distance to start node is 0
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        // Visit all neighbors
        for (size_t i = 0; i < g.adj[u].size(); ++i) {
            int v = g.adj[u][i];
            if (dist[v] == -1) { // Not visited yet
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return order;
}

// Helper function for DFS
void dfsUtil(const Graph& g, int u, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;                  // Mark current node as visited
    order.push_back(u);           // Add to traversal order

    // Recurse for all unvisited neighbors
    for (size_t i = 0; i < g.adj[u].size(); ++i) {
        int v = g.adj[u][i];
        if (!vis[v]) dfsUtil(g, v, vis, order);
    }
}

// DFS traversal from start node s
vector<int> dfs(const Graph& g, int s) {
    vector<int> order;           // Order of visited nodes
    vector<int> vis(g.n, 0);     // Visited array
    dfsUtil(g, s, vis, order);
    return order;
}

// Recursive helper for detecting cycles in directed graph
bool hasDirectedCycleUtil(const Graph& g, int u, vector<int>& state) {
    // state: 0 = unvisited, 1 = visiting, 2 = done
    state[u] = 1;  // Mark as visiting

    for (size_t i = 0; i < g.adj[u].size(); ++i) {
        int v = g.adj[u][i];
        if (state[v] == 0) { // Not visited
            if (hasDirectedCycleUtil(g, v, state)) return true;
        } else if (state[v] == 1) { // Back-edge found
            return true;
        }
    }

    state[u] = 2; // Finished exploring
    return false;
}

// Detect cycle in the whole graph (only for directed)
bool hasDirectedCycle(const Graph& g) {
    if (g.undirected) return false; // Not used for undirected graphs
    vector<int> state(g.n, 0);      // Initialize state for all vertices

    for (int u = 0; u < g.n; ++u)
        if (state[u] == 0 && hasDirectedCycleUtil(g, u, state))
            return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;                  // Number of vertices and edges

    bool undirected = false;         // Change to true if graph is undirected
    Graph g(n, undirected);

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start; 
    cin >> start;                    // Starting node for BFS/DFS

    // Perform traversals and cycle detection
    vector<int> b = bfs(g, start);
    vector<int> d = dfs(g, start);
    bool cyc = hasDirectedCycle(g);

    // Output results
    cout << "BFS:";
    for (size_t i = 0; i < b.size(); ++i) cout << ' ' << b[i];
    cout << "\nDFS:";
    for (size_t i = 0; i < d.size(); ++i) cout << ' ' << d[i];
    cout << "\nDirected cycle: " << (cyc ? "YES" : "NO") << "\n";

    return 0;
}
