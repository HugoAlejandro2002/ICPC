#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void build(const vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        tree[x] = max(tree[2*x + 1], tree[2*x + 2]);
    }

    void build(const vector<int> &a) {
        build(a, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if (i < m) update(i, v, 2*x + 1, lx, m);
        else update(i, v, 2*x + 2, m, rx);
        tree[x] = max(tree[2*x + 1], tree[2*x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    // Find first index with value >= val
    int find(int val, int x, int lx, int rx) {
        if (tree[x] < val) return -1; // no hotel in this segment has enough rooms
        if (rx - lx == 1) return lx; // leaf node, found the hotel
        int m = (lx + rx) / 2;
        int res = find(val, 2*x + 1, lx, m);
        if (res == -1) res = find(val, 2*x + 2, m, rx);
        return res;
    }

    int find(int val) {
        return find(val, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    SegmentTree st;
    st.init(n);
    st.build(h);

    for (int i = 0; i < m; i++) {
        int r; cin >> r;
        int idx = st.find(r);
        if (idx == -1) {
            cout << 0 << " ";
        } else {
            cout << idx + 1 << " "; // hotels numbered from 1
            h[idx] -= r;
            st.update(idx, h[idx]);
        }
    }
    cout << "\n";

    return 0;
}
