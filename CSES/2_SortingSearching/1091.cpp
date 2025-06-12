#include <bits/stdc++.h>
using namespace std;

#define input freopen("B.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x,y) cout << #x<<" = "<<x<<", " <<#y<<" =" <<y<< endl
#define show3(x,y,z) cout << #x<<" = "<<x<<", " <<#y<<" = " <<y<< ", " <<#z<<" = " <<z<< endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,x,t;
    cin>>n>>m;
    
    multiset<int> h;

    for (int i = 0; i < n; i++){
        cin>>x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++){
        cin>>t;
        auto ticket = h.upper_bound(t);
        if (ticket==h.begin()){
            cout<<"-1\n";
        } else {
            ticket--;
            h.erase(ticket);
            cout<<*ticket<<'\n';
        }
    }
    
    return 0;
}