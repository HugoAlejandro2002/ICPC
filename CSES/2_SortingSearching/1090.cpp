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
    
    int n,x;
    cin>>n>>x;
    
    int p[n];

    for (int i = 0; i < n; i++)
        cin>>p[i];

    sort(p,p+n);
    
    int i=0,j=n-1,sol=0;
    while (i < j)
    {
        if (p[i]+p[j]<=x){
            i++;j--;
        } else {
            j--;
        }
        sol++;
    }
    if(i==j) sol++;
    
    cout<<sol<<'\n';
    
    return 0;
}