#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

using namespace std;

struct Node {
    int color;
    vector<int> edges;
};

vector<Node> tree;
vector<long long> subtreeCount;
unordered_map<int, int> colorCount;

void dfs(int node, int parent) {
    colorCount[tree[node].color]++;
    for (int child : tree[node].edges) {
        if (child != parent) {
            dfs(child, node);
        }
    }
    colorCount[tree[node].color]--;
    subtreeCount[parent] += subtreeCount[node];
}

void calculateSubtreeCounts(int root) {
    subtreeCount.resize(tree.size());
    dfs(root, -1);
}

int main() {
    input;
    int N;
    cin >> N;

    tree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> tree[i].color;
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].edges.push_back(v);
        tree[v].edges.push_back(u);
    }

    calculateSubtreeCounts(1);

    long long totalTediousPaths = 0;
    for (int i = 2; i <= N; i++) {
        totalTediousPaths += subtreeCount[i] * (N - subtreeCount[i]);
    }

    for (int i = 1; i < N; i++) {
        cout << totalTediousPaths << " ";
        totalTediousPaths -= subtreeCount[i] * (N - subtreeCount[i]);
    }
    cout << endl;

    return 0;
}