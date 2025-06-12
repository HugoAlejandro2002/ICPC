#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vi price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    // dp[i][j] = max pages using first i+1 books with budget j
    vvi dp(n, vi(x + 1, 0));

    // Base case: using only the first book
    for (int j = 0; j <= x; j++) {
        if (j >= price[0]) dp[0][j] = pages[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            // Exclude the current book
            dp[i][j] = dp[i - 1][j];
            // Include the current book if possible
            if (j >= price[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
            }
        }
    }

    cout << dp[n - 1][x] << '\n';
    return 0;
}
