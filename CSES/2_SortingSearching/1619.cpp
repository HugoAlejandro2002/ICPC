#include <bits/stdc++.h>
using namespace std;

#define input freopen("B.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b;cin>>n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        if(m.find(a)!=m.end()){
            m.emplace(a,1);
        } else {
            m[a]++;
        }
        if(m.find(b)!=m.end()){
            m.emplace(b,-1);
        } else {
            m[b]--;
        }
    }

    int maxv = 0,curr=0;
    for (auto &p: m)
    {
        curr+=p.second;
        maxv=max(maxv,curr);
    }

    cout<<maxv<<'\n';
    
    return 0;
}