#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll INF = 1e15;
const ll MAXN = 501;
ll dist[MAXN][MAXN];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    // Initialize distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    
    // Read edges
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        if (c < dist[a][b]) {
            dist[a][b] = c;
            dist[b][a] = c; // undirected graph
        }
    }
    
    // O(n^3)
    // Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            ll dik = dist[i][k];
            if (dik == INF) continue;
            for (int j = 1; j <= n; j++) {
                ll dkj = dist[k][j];
                if (dkj == INF) continue;
                if (dik + dkj < dist[i][j]) {
                    dist[i][j] = dik + dkj;
                }
            }
        }
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << -1 << "\n";
        else cout << dist[a][b] << "\n";
    }

    return 0;
}
