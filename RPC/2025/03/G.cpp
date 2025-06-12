#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define forr(i, a, b) for (int i = ((a) < (b) ? (a) : (a) - 1); (a) < (b) ? i < (b) : i >= (b); (a) < (b) ? i++ : i--)
#define FORR(i, a, b) for (long long i = ((a) < (b) ? (a) : (a) - 1); (a) < (b) ? i < (b) : i >= (b); (a) < (b) ? i++ : i--)
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define each(x, a) for (auto &x : a)
#define sq(a) ((a) * (a))

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;

const ll MOD = 1e9 + 7;

ll n, sol = 0;
string camino;

int main()
{
    fast_io;
    // input;
    cin >> n;
    cin >> camino;
    vector<vll> dp(450, vll(n+1,0));
    dp[2][0]=1;
    int ini=0;
    for(int j=2;j<450;j++)
    {
        for(int i=ini;i<n;i++)
        {
        if(camino[i]=='#') {
            continue;
        }
        if (i + 1 >= n)
        {
            sol = (sol + dp[j][i]) % MOD;
        }
        else
        {
            dp[j][i+1]= (dp[j][i+1]+dp[j][i]) % MOD;
        }
        if (i + j >= n)
        {
            sol = (sol + dp[j][i]) % MOD;
        }
        else
        {
            dp[j+1][i+j]= (dp[j+1][i+j]+dp[j][i]) % MOD;
        }}
        ini+=j;
    }
    cout << sol << '\n';
    return 0;
}