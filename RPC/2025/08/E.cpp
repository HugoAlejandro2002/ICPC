#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;
struct Code {
    int p1, p2, v,idx;
};

int main(){
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin>>n;
    Code vc[n];
    for (int i = 0; i < n; i++)
    {
        cin>>p;
        vc[p-1].idx = p;
        vc[p-1].p1 = n-i;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>vc[i].v;
    }

    sort(vc, vc+n, [](const Code& a, const Code& b) {
        return a.v>b.v;
    });

    for(int i=0;i<n;i++) {
        vc[i].p2 = n-i;
    }

    sort(vc, vc+n, [](const Code& a, const Code& b) {
        if (a.p1+a.p2 == b.p1+b.p2) return a.p2 > b.p2;
        return a.p1+a.p2 > b.p1+b.p2;
    });

    for(int i=0;i<n;i++) {
        cout<<i+1<<". Kod"<<((vc[i].idx>9)?"":"0")<<vc[i].idx<<" ("<<vc[i].p1+vc[i].p2<<")\n";
    }
    
    return 0;
}