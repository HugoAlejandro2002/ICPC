#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 1e6;
vi adj[MAXN];
bool visited[MAXN];
bool team[MAXN];

bool dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (team[v]==team[u]){
            return 0;
        } else {
            team[v]=1-team[u];
        }
        if (!visited[v]){
            if (!dfs(v)) return 0;
        }
    }
    return 1;
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

    memset(visited, 0, sizeof visited);
    memset(team, -1, sizeof team);
    bool result=true;
    for (int i = 1; i <= n; i++)
    if (!visited[i]){
        team[i]=0;
        result &= dfs(i);
    }
    
    if(result){
        cout<<"1";
        for (int i = 2; i <= n; i++)
        {
            cout<<' '<<team[i]+1;
        }
        cout<<'\n';
    } else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
