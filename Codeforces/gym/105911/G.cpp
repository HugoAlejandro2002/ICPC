#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,Q,u,v,d;
    cin>>n>>m>>Q;
    
    vvii G(n+1);
    
    ll dp[n+1][31];
    while (m--)
    {
        cin>>u>>v>>d;
        G[u].push_back({v,d});
    }

    for (int i = 1; i < n+1; i++)
    {
        dp[i][1] = 1;
        for (int j = 0; j < G[i].size(); j++)
        {
            dp[i][1] = max(dp[i][1], G[i][j].second);
        }
    }
    for (int k =2; k < 31; k++)
    {   
        for (int i = 1; i < n+1; i++)
        {
            dp[i][k] = 1;
            for (int j = 0; j < G[i].size(); j++)
            {
                dp[i][k] = max(dp[i][k], dp[G[i][j].first][k-1]*G[i][j].second);
            }
        }
    }

    // for (int i = 1; i < n+1; i++)
    // {
    //     for (int j = 1; j < 31; j++)
    //     {
    //         cout<<dp[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }
    

    int p,x;
    while(Q--){
        cin>>p>>x;
        for (int i = 1; i < 31; i++)
        {
            if (dp[p][i]>x) {
                cout<<i<<endl;
                break;
            }
        }
        
    }
    
    return 0;
}