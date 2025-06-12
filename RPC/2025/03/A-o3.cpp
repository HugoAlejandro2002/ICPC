#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int n, m;
vector<vector<int>> adj;
vector<int> deg;

/* articulation points */
vector<int> disc, low;
vector<char> isArtic;
int dfsTime = 0;

void dfs(int u, int parent, int root, int &rootChildren) {
    disc[u] = low[u] = ++dfsTime;
    for (int v : adj[u]) {
        if (!disc[v]) {
            if (parent == -1) ++rootChildren;
            dfs(v, u, root, rootChildren);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u]) isArtic[u] = 1;
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;
    adj.assign(n + 1, {});
    deg.assign(n + 1, 0);

    vector<pair<int,int>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a];
        ++deg[b];
        edges.emplace_back(a, b);
    }

    /* neighbour info */
    vector<int> cntDeg2(n + 1, 0);
    vector<char> hasDeg1Neighbour(n + 1, 0);

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (deg[v] == 1) hasDeg1Neighbour[u] = 1;
            else if (deg[v] == 2) ++cntDeg2[u];
        }
    }

    int D1 = 0, badDegCnt = 0, badVertex = -1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) ++D1;
        if (!(deg[i] >= 1 && deg[i] <= 3)) {
            ++badDegCnt;
            badVertex = i;
        }
    }
    if (badDegCnt > 1) {
        cout << "no\n";
        return 0;
    }

    /* articulation points & component count */
    disc.assign(n + 1, 0);
    low.assign(n + 1, 0);
    isArtic.assign(n + 1, 0);
    dfsTime = 0;
    int components = 0;

    for (int i = 1; i <= n; ++i) if (!disc[i]) {
        ++components;
        int rootChildren = 0;
        dfs(i, -1, i, rootChildren);
        if (rootChildren > 1) isArtic[i] = 1;
    }

    if (components > 2) {
        cout << "no\n";
        return 0;
    }

    auto feasible = [&](int v) -> bool {
        int D1_other = D1 - (deg[v] == 1 ? 1 : 0);
        if (D1_other > 2 || D1_other < 0) return false;
        if (hasDeg1Neighbour[v]) return false;
        int needDeg2 = 2 - D1_other;
        if (needDeg2 < 0 || cntDeg2[v] != needDeg2) return false;
        if (m - deg[v] != n - 2) return false;

        if (components == 1) {
            if (isArtic[v]) return false;
        } else {               /* components == 2 */
            if (deg[v] != 0) return false;
        }
        /* all checks passed */
        return true;
    };

    if (badDegCnt == 1) {
        if (feasible(badVertex)) {
            cout << "yes\n";
            return 0;
        }
    } else {
        for (int v = 1; v <= n; ++v) {
            if (feasible(v)) {
                cout << "yes\n";
                return 0;
            }
        }
    }
    cout << "no\n";
    return 0;
}