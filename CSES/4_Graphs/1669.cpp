#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 1e6;
vi adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int sol;

bool dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]){
            parent[v]=u;
            if (dfs(v)) return 1;
        } else {
            if (parent[u]!=v){
                parent[v]=u;
                sol = u;
                return 1;
            }
        }
    }
    return 0;
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
    memset(parent, -1, sizeof parent);
    bool result=0;
    for (int i = 1; i <= n; i++)
    if (!visited[i] && dfs(i)){
        result=1;
        break;
    }
    
    if(result){
        vi path = {sol};
        int node = parent[sol];
        while(node!=sol)
        {
            path.push_back(node);
            node=parent[node];
        }
        cout<<path.size()+1<<'\n';
        for (int &p : path)
        {
            cout<<p<<' ';
        }
        
        cout<<sol<<'\n';
    } else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
