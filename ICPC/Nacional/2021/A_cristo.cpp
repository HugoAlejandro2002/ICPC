#include<iostream>
#define input freopen("in.txt","r",stdin)

using namespace std;

int dp[100];

void solve_dp(){
    dp[1]=1;dp[2]=2;dp[3]=4;
    for (int i = 4; i < 101; i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
}

int main(){
    input;
    solve_dp();
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;

        cout<<dp[x]<<endl;
    }
    

    return 0;
}