#include <bits/stdc++.h>
using namespace std;

#define input freopen("B.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x,y) cout << #x<<" = "<<x<<", " <<#y<<" =" <<y<< endl
#define show3(x,y,z) cout << #x<<" = "<<x<<", " <<#y<<" = " <<y<< ", " <<#z<<" = " <<z<< endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;
    
    int a[n];
    int b[m];

    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < m; i++)
        cin>>b[i];

    sort(a,a+n);
    sort(b,b+m);

    int i=0,j=0,sol=0;
    while (i < m && j<n)
    {
        if (a[j]-b[i]>k){
            i++;
            continue;
        } 
        if (b[i]-a[j]>k){
            j++;
            continue;
        }
        sol++;
        j++;i++;
    }
    
    cout<<sol<<'\n';
    
    return 0;
}