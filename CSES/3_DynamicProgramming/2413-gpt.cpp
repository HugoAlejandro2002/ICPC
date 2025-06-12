#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
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

    int t;
    cin >> t;
    vi queries(t);
    int max_n = 0;
    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    vector<ll> dp(max_n + 1);
    dp[0] = 1;
    if (max_n >= 1) dp[1] = 2;
    if (max_n >= 2) dp[2] = 8;

    for (int i = 3; i <= max_n; ++i) {
        dp[i] = (6 * dp[i - 1] % MOD - 7 * dp[i - 2] % MOD + MOD) % MOD;
    }

    for (int i = 0; i < t; ++i) {
        cout << dp[queries[i]] << '\n';
    }

    return 0;
}
