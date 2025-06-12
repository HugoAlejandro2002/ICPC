#include <bits/stdc++.h>
using namespace std;

#define input freopen("B.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

void printBin(int n, int num)
{
    for (int i = n - 1; i >= 0; i--)
        cout << bool(num & (1 << i));
    cout << '\n';
}

int main()
{
    // input;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    bool used[1 << n];
    memset(used, 0, sizeof used);

    int current = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        printBin(n, current);
        used[current] = 1;
        for (int j = 0; j < n; j++)
        {
            int next = current ^ (1 << j);
            if (!used[next])
            {
                used[next] = 1;
                current = next;
                break;
            }
        }
    }

    // Gray code formula
    // for (int i = 0; i < (1<<n); i++){
    //     printBin(n, i ^ (i >> 1));
    // }
    return 0;
}