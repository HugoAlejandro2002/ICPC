#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0); // change default value if needed
    }

    // Modify this function for the operation you want (sum, min, max, etc.)
    int combine(int a, int b) {
        return a + b; // sum
        // return min(a, b); // min
        // return max(a, b); // max
        // return __gcd(a, b); // gcd
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void build(vector<int>& a) {
        build(a, 1, 0, n - 1);
    }

    // Query in range [l, r]
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0; // change identity element for your operation
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        return combine(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // Point update: a[pos] = new_val
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int pos, int new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    SegmentTree st(n);
    st.build(a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            st.update(pos, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}
