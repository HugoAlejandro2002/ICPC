#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll dp[MAXN][2];

int main() {
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    dp[1][0] = 1;
    dp[1][1] = 1;
    
    for(int i = 2; i < MAXN; i++) {
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-1][0]+4*dp[i-1][1])%MOD;
    }
    
    int t,n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << (dp[n][0]+dp[n][1])%MOD << '\n';
    }

    return 0;
}
