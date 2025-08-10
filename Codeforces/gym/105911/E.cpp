#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)

const int A = 26; // Alphabet size
const int MAXN = 1e5 + 5;
int k; // Modulo divisor

int block_size;

// Custom hash for array<int, A> to use in unordered_map
struct custom_hash
{
    size_t operator()(const array<int, A> &a) const
    {
        uint64_t h = 0;
        for (int x : a)
            h = h * 31 + x;
        return h;
    }
};

struct Code
{
    int l, r, idx;
    bool operator<(const Code &other) const
    {
        int b1 = l / block_size, b2 = other.l / block_size;
        if (b1 != b2)
            return b1 < b2;
        return (b1 & 1) ? (r > other.r) : (r < other.r);
    }
};

vector<long long> freq;
vector<int> id;
vector<long long> ans;
long long total = 0;

void add(int i)
{
    long long &fr = freq[id[i]];
    total += fr;
    fr++;
}

void remove(int i)
{
    long long &fr = freq[id[i]];
    fr--;
    total -= fr;
}

int main()
{
    // input;
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int n, q;
    cin >> n >> k >> q;
    cin >> s;

    block_size = sqrt(n);

    freq.resize(n+1);
    id.resize(n+1);
    // Compute prefix masks
    vector<array<int, A>> prefix(n + 1);
    unordered_map<array<int, A>, int, custom_hash> id_of;
    id_of.reserve(n*2);
    for (int i = 0; i < n; ++i)
    {
        prefix[i + 1] = prefix[i];
        prefix[i + 1][s[i] - 'a'] = (prefix[i + 1][s[i] - 'a'] + 1) % k;
    }
    for (int i = 0; i <= n; ++i)
    {
        auto it = id_of.find(prefix[i]);
        if (it==id_of.end()) {
            int new_id = id_of.size();
            id_of.emplace(prefix[i], new_id);
            id[i] = new_id;
        } else {
            id[i]= it->second;
        }
    }

    vector<Code> queries(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
        queries[i].r++; // convert to [l-1, r] for prefix comparison
        queries[i].l--;
    }

    sort(queries.begin(), queries.end());

    int L = 0, R = 1;
    freq[id[0]] = 1; // Initial mask count
    ans.resize(q);

    for (const auto &query : queries)
    {
        int l = query.l, r = query.r;
        while (R < r)
            add(R++);
        while (L > l)
            add(--L);
        while (R > r)
            remove(--R);
        while (L < l)
            remove(L++);
        ans[query.idx] = total;
    }

    for (auto a : ans) cout << a << '\n';

    return 0;
}