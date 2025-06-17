#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " = " << x << endl

typedef vector<int> vi;

const int MAXN = 1e6;
int n, m;
vi adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                if (v==n){
                    return;
                }
                q.push(v);
            }
        }
    }
}

int main() {
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
    bfs(1);
    if (parent[n]!=-1){
        vi path;
        int node = n;
        while(node!=1){
            // show(node);
            path.push_back(node);
            node=parent[node];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()+1<<"\n1";
        for(int &p: path){
            cout<<' '<<p;
        }
        cout<<'\n';
    } else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
