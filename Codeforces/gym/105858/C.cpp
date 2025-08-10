#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl

typedef unsigned long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    // input;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int a = A.size();
    int b = B.size();

    priority_queue<int, vector<int>, greater<int>> nums;
    for (int i = 0; i < a; i++)
        nums.push(A[i] - '0');
    for (int i = 0; i < b; i++)
        nums.push(B[i] - '0');

    vi ten(10);
    ten[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        ten[i] = 10 * ten[i - 1];
    }
    ll mod = 998244353;
    ll tenMod = ten[9]%mod;
    vi groups = {1, 1};

    int db = min(a, b);
    int ti = 0, group = 0;
    ll sum, sol = 0;
    int num1, num2;
    // show(db);
    while (!nums.empty())
    {
        sum = 0;
        for (int i = 0; i < 9; i++, ti++)
        {
            if (nums.empty())
            break;
            num1 = nums.top();
            nums.pop();
            if (ti < db)
            {
                num2 = nums.top();
                nums.pop();
            }
            else
            {
                num2 = 0;
            }
            // show(num1);
            // show(num2);
            ll block = (num1 + num2) * ten[i];
            sum += block;
            // show(sum);
        }
        group++;
        ll nblock = ((sum % mod) * groups[group]) % mod;
        sol = (sol+nblock)%mod;
        groups.push_back((groups[group]*tenMod)%mod);
    }

    cout<<sol<<'\n';

    return 0;
}