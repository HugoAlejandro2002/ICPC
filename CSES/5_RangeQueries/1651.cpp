#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
public:
    int n, size;
    vector<long long> tree, lazy;

    LazySegmentTree(const vector<int>& data) {
        n = data.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
        lazy.assign(2 * size, 0);

        for (int i = 0; i < n; ++i)
            tree[size + i] = data[i];
        for (int i = size - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    // ───────────────────────────────────────
    // Lazy Propagation Methods
    // ───────────────────────────────────────

    void apply(int idx, long long value, int length) {
        tree[idx] += value * length;
        if (idx < size) {
            lazy[idx] += value;
        }
    }

    void push(int idx, int length) {
        if (lazy[idx] != 0) {
            apply(idx << 1, lazy[idx], length >> 1);
            apply(idx << 1 | 1, lazy[idx], length >> 1);
            lazy[idx] = 0;
        }
    }

    void update_range(int left, int right, long long value) {
        update_range(left, right, value, 1, 0, size);
    }

    void update_range(int left, int right, long long value, int idx, int l, int r) {
        if (right <= l || r <= left)
            return;
        if (left <= l && r <= right) {
            apply(idx, value, r - l);
            return;
        }
        push(idx, r - l);
        int mid = (l + r) >> 1;
        update_range(left, right, value, idx << 1, l, mid);
        update_range(left, right, value, idx << 1 | 1, mid, r);
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }

    long long query(int left, int right) {
        return query(left, right, 1, 0, size);
    }

    long long query(int left, int right, int idx, int l, int r) {
        if (right <= l || r <= left)
            return 0;
        if (left <= l && r <= right)
            return tree[idx];
        push(idx, r - l);
        int mid = (l + r) >> 1;
        return query(left, right, idx << 1, l, mid) +
               query(left, right, idx << 1 | 1, mid, r);
    }

    long long get(int index) {
        int idx = index + size;
        vector<int> path;
        for (int i = idx; i > 1; i >>= 1)
            path.push_back(i >> 1);
        reverse(path.begin(), path.end());
        for (int node : path) {
            int len = size >> (__lg(node));
            push(node, len);
        }
        return tree[idx];
    }

    // ───────────────────────────────────────
    // Non-Lazy Methods
    // ───────────────────────────────────────

    void point_update(int index, long long value) {
        int idx = index + size;
        tree[idx] = value;
        for (idx >>= 1; idx >= 1; idx >>= 1)
            tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }

    long long query_range_non_lazy(int left, int right) {
        long long res = 0;
        left += size;
        right += size;
        while (left < right) {
            if (left & 1) res += tree[left++];
            if (right & 1) res += tree[--right];
            left >>= 1;
            right >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    LazySegmentTree st(arr);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            st.update_range(l - 1, r, val);
        } else {
            int idx;
            cin >> idx;
            cout << st.query(idx - 1, idx) << '\n';
        }
    }

    return 0;
}
