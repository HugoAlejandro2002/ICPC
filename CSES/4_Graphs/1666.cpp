#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MAXN = 1e6;
vi adj[MAXN];
bool visited[MAXN];

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
    int last = -1;
    memset(visited, 0, sizeof visited);
    vii roads;
    for (int start = 1; start <= n; start++)
    {
        if (!visited[start]) {
            dfs(start);
            if(last!=-1){
                roads.push_back({last,start});
            }
            last=start;
        }
    }

    cout<<roads.size()<<'\n';
    for (ii &road : roads) {
        cout<<road.first<<' '<<road.second<<'\n';
    }
    
    return 0;   
}
