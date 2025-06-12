#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, h;
ll dp[301][301];
int x[301];

ll solve(int l, int r){
    if(l==r) return h;
    if(dp[l][r]!=-1) return dp[l][r];
    ll result = 1e12;
    ll hlr=max(0,h+1-(x[r]-x[l]+1)/2);
    for (int m = l; m < r; m++)
    {
        ll partial = solve(l,m)+solve(m+1,r)-hlr;
        result=min(result,partial);
    }
    return dp[l][r]=result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>h;

    memset(dp,-1,sizeof dp);

    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }

    cout<<solve(0,n-1)<<'\n';

    
    return 0;
}
