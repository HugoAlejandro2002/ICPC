#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, int> lli;
typedef pair<int, ll> ill;

const int MAXN = 1e6;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // input;
    int n,t;
    cin>>n>>t;
    int k=20;
    vi A(k,0);
    vi B(k,0);

    set<ll> as;
    set<ll> bs;
    for(int i=0; i<(n/2)+(n%2); i++) {
        cin>>A[i];
        // show(A[i]);
        }
    for(int i=0; i<(n/2); i++) cin>>B[i];

    ll sol=0;
    for (int i = 0; i < 1<<k; i++)
    {
        ll sum =0;
        for (int j = 0; j < k; j++)
        {
            if(i&(1<<j)){
                sum+=A[j];
                // show(A[j]);
            }
        }
        if (sum<=t){
            as.insert(sum);
            sol=max(sol,sum);
            // show(sol);        
        }
    }
    for (int i = 0; i < 1<<k; i++)
    {
        ll sum =0;
        for (int j = 0; j < k; j++)
        {
            if(i&1<<j){
                sum+=B[j];
            }
        }
        if (sum<=t){
            bs.insert(sum);
            sol=max(sol,sum);
        }
    }

    for (auto a:as)
    {
        auto it = prev(bs.upper_bound(t-a));
        if (it!=bs.end())
        sol=max(sol,a+ (*it));
    }
    
    cout<<sol<<'\n';

    // ll ans = max(fn(i+1),fn(,i+1));


    // cout<<ans<<'\n';

    return 0;
}
