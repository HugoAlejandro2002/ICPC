#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MOD = 1e9+7;
vi dp;

int solve(int n){
    if (n==0) return 1;
    if(dp[n]!=-1) return dp[n];

    int sol=0;
    for (int i = 1; i < 7; i++)
    {
        if(n-i>=0){
            sol=(solve(n-i)%MOD+sol)%MOD;
        }
    }
    return dp[n]=sol;
}

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    dp.resize(n+1,-1);

    cout<<solve(n)<<'\n';
    return 0;
}