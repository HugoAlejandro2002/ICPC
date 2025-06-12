#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // Initialize multiples of c[0]
    for (int i = c[0]; i <= x; i += c[0]) {
        dp[0][i] = 1;
    }

    for (int j = 1; j < n; ++j) {
        if (c[j] > x) continue;
        dp[j][c[j]] = 1;
        for (int i = 0; i <= x; ++i) {
            dp[j][i] = (dp[j][i] + dp[j - 1][i]) % MOD;
            if (dp[j][i] == 0) continue;
            if (i + c[j] > x) continue;
            dp[j][i + c[j]] = (dp[j][i + c[j]] + dp[j][i]) % MOD;
        }
    }

    cout << dp[n - 1][x] << '\n';
    return 0;
}
