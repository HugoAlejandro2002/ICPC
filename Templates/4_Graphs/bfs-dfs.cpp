#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 1e6;
vi adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m; // number of nodes and edges
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // assuming undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    memset(visited, 0, sizeof visited);
    bfs(start);
    dfs(start);
    return 0;
}
