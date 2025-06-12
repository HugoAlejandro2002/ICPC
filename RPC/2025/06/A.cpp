#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    // show(n);
    int x[n],valid[n];
    // vi x(n), y(n);
    memset(valid,0,sizeof valid);
    int mi=1000001,ma=0;
    for (int i = 0; i < n; i++){
        cin>>x[i];
        ma=max(ma,x[i]);
        if (x[i]==ma) valid[i]++;
    }
    
    int sol = 0,pr=0;
    for (int i = n-1; i >= 0; i--)
    {
        mi=min(mi,x[i]);
        if (x[i]==mi) valid[i]++;
        if(valid[i]==2) sol++;
    }

    cout<<sol;
    if (sol){
        for (int i = 0; i < n; i++)
        {
            if(valid[i]==2) {
                cout<<" "<<x[i];
                pr++;
                if(pr==100) break;
            }
        }    
    }
    cout<<'\n';
    
    return 0;
}