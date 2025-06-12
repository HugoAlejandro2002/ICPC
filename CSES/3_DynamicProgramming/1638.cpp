#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vi> dp(n, vi(n,0));
    vector<string> G(n);
    for (int i = 0; i < n; ++i) 
        cin >> G[i];

    if (G[0][0]=='*' || G[n-1][n-1]=='*'){
        cout<<0<<'\n';
        return 0;
    }
    dp[0][0]=1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(G[i][j]=='*') continue;
            if(i+1<n && G[i+1][j]!='*') {
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            }
            if(j+1<n && G[i][j+1]!='*') {
                dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD;
            }
        }
    }
    

    cout << dp[n - 1][n-1] << '\n';
    return 0;
}
