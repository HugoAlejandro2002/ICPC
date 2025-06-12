#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define debug(x) cout<<#x<<" = "<<x<<endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

ll sum(ll n)
{
    if (n < 0)
        return 0;
    return n * (n + 1) / 2;
}

int main()
{
    //input;
    int t, n, k, q;
    cin>>t;
    while (t--)
    {
        cin >> n >> k >> q;

        int a[n];
        ll sol = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= q)
            {
                count++;
            }
            else
            {
                // debug(count);
                sol += sum(count - k+1);
                count = 0;
            }
        }
        // debug(count);
        sol += sum(count - k+1);
        
        cout<<sol<<endl;

    }
    return 0;
}