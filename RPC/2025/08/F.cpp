#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vi d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    // Duplicate the playlist to handle circularity
    vi dd = d;
    dd.insert(dd.end(), d.begin(), d.end());
    int total_len = 2 * n;
    vi P(total_len + 1, 0);
    for (int i = 1; i <= total_len; ++i) {
        P[i] = P[i - 1] + dd[i - 1];
    }

    // Precompute next_ad[i] = first j >= i where P[j+1] - P[i] >= c
    vi next_ad(total_len, total_len);
    int j = 0;
    for (int i = 0; i < total_len; ++i) {
        if (j < i) j = i;
        while (j < total_len && P[j + 1] - P[i] < c) {
            ++j;
        }
        if (j < total_len && P[j + 1] - P[i] >= c) {
            next_ad[i] = j;
        } else {
            next_ad[i] = total_len;
        }
    }

    const int LOG = 21;
    vvi dp(LOG, vi(total_len + 1, total_len));
    vvi cnt(LOG, vi(total_len + 1, 0));

    // Initialize dp[0][i] and cnt[0][i]
    for (int i = 0; i < total_len; ++i) {
        if (next_ad[i] < total_len) {
            int next_start = next_ad[i] + 1;
            if (next_start > total_len) next_start = total_len;
            dp[0][i] = next_start;
            cnt[0][i] = 1;
        } else {
            dp[0][i] = total_len;
            cnt[0][i] = 0;
        }
    }
    dp[0][total_len] = total_len;
    cnt[0][total_len] = 0;

    // Build binary lifting tables
    for (int k = 1; k < LOG; ++k) {
        for (int i = 0; i <= total_len; ++i) {
            int mid = dp[k - 1][i];
            dp[k][i] = dp[k - 1][mid];
            cnt[k][i] = cnt[k - 1][i] + cnt[k - 1][mid];
        }
    }

    // Process each starting position
    vi res(n, 0);
    for (int i = 0; i < n; ++i) {
        int cur = i;
        int ads = 0;
        for (int k = LOG - 1; k >= 0; --k) {
            if (dp[k][cur] < i + n) {
                ads += cnt[k][cur];
                cur = dp[k][cur];
            }
        }
        res[i] = ads;
    }

    // Output the results
    for (int i = 0; i < n-1; ++i) {
        cout << res[i] << " ";
    }
    cout <<res[n-1] << '\n';

    return 0;
}