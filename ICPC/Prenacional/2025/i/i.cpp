#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    // input;
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int n; cin>>n;

    ii dp[2*n+1];
    string nm[n];
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin>>nm[i];
        cin>>d[i];

        // show(nm[i]);
        // show(d[i]);

        dp[n+i]={i,d[i]};
    }

    int index=n+n-1;
    while (index>1){
        // show(index);
        int target=index/2;
        ii a =dp[index];
        ii b =dp[index-1];
        dp[target] = a.second==b.second? 
            nm[a.first]<nm[b.first]? 
                make_pair(a.first,0):make_pair(b.first,0)
                : a.second>b.second? make_pair(a.first,a.second-b.second):make_pair(b.first,b.second-a.second)
                ;
        index-=2;
    }
    
    cout<<nm[dp[1].first]<<'\n';
    cout<<nm[(dp[1].first==dp[2].first)?dp[3].first:dp[2].first]<<'\n';
    
    return 0;
}