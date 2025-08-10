#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool posi = a[0] > 0;
    ll sol = 0, currP = 0, currN = 0;
    int currMax = -1000000001;
    for (int i = 0; i < n; i++)
    {
        if ((posi && a[i] > 0) || (!posi && a[i] < 0))
        {
            currMax = max(currMax, a[i]);
        }
        else
        {
            if (posi)
            {
                currP = max(currP, currN + currMax);
                sol = max(sol, currP);
            }
            else
            {
                currN = max(currN, currP + currMax);
                sol = max(sol, currN);
            }
            posi = !posi;
            currMax = -1000000001;
            i--;
        }
    }

    if (posi)
    {
        currP = max(currP, currN + currMax);
        sol = max(sol, currP);
    }
    else
    {
        currN = max(currN, currP + currMax);
        sol = max(sol, currN);
    }

    cout << sol << '\n';

    return 0;
}