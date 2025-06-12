#include <bits/stdc++.h>
using namespace std;

int n, q, block;
struct Query {
    int l, r, idx;
    bool operator<(const Query &o) const {
        int b1 = l / block, b2 = o.l / block;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r > o.r) : (r < o.r);
    }
};

// Global state for answer
long long current_answer = 0;

void add(int i) {
    // Add element a[i] to data structure
}

void remove(int i) {
    // Remove element a[i] from data structure
}

int main() {
    cin >> n >> q;

    block = (int) sqrt(n);

    int a[n];
    Query queries[n];
    long long ans[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        // Queries are [l,r], adjust if necessary
        // queries[i].l--; queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries, queries + q);

    int L = 0, R = -1;
    for (int i = 0; i < q; i++) {
        while (R < queries[i].r) add(++R);
        while (R > queries[i].r) remove(R--);
        while (L < queries[i].l) remove(L++);
        while (L > queries[i].l) add(--L);
        ans[queries[i].idx] = current_answer;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}
