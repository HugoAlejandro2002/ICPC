#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vi x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vvi dp(n, vi(m + 2, 0)); // +2 to avoid bounds check on v-1 and v+1

    // Base case
    if (x[0] == 0) {
        for (int v = 1; v <= m; ++v) dp[0][v] = 1;
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (x[i] == 0) {
            for (int v = 1; v <= m; ++v) {
                dp[i][v] = ((dp[i - 1][v - 1] + dp[i - 1][v]) % MOD + dp[i - 1][v + 1]) % MOD;
            }
        } else {
            int v = x[i];
            dp[i][v] = ((dp[i - 1][v - 1] + dp[i - 1][v]) % MOD + dp[i - 1][v + 1]) % MOD;
        }
    }

    int ans = 0;
    for (int v = 1; v <= m; ++v) {
        ans = (ans + dp[n - 1][v]) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
