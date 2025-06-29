#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, int> lli;
typedef pair<int, ll> ill;

const int MAXN = 1e6;
const ll INF = 1e18;

int n, m, k; // global
vector<ill> adj[MAXN];
ll dist[MAXN];

//O((n+m)*log(n))
void dijkstra(int src) {
    fill(dist, dist + (n+1), INF); // use global n
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // input;
    
    cin >> n >> m >>k;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); //vector<T> => emplace_back(...args) == T(...args)
        adj[v].emplace_back(u, w); // For undirected graph
    }

    dijkstra(1);
    if (dist[n] <= k)
    cout<<"SI";
    else cout<<"NO";
    
    
    cout<<'\n';

    return 0;
}
