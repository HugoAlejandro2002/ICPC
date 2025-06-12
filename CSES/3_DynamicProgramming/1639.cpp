#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MOD = 1e9+7;

string ns,ms; 
vvi dp;

int solve(int n,int m){
    if (n==0) return m;
    if (m==0) return n;
    if(dp[n][m]!=-1) return dp[n][m];

    char cn=ns[n-1];
    char cm=ms[m-1];
    if (cn==cm) return dp[n][m]=solve(n-1,m-1);

    return dp[n][m]=min(solve(n,m-1),min(solve(n-1,m-1),solve(n-1,m)))+1;
}

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>ns>>ms;
    int n=ns.size();
    int m=ms.size();

    dp.resize(n+1,vi(m+1,-1));

    cout<<solve(n,m)<<'\n';
    return 0;
}