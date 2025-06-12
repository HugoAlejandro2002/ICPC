#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define debug(x) cout<<#x<<" = "<<x<<endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    //input;
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        // debug(n);
        cout<<((log2(n)<k)?(n+1):(1<<k))<<endl;
    }
    return 0;
}