#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int toD(string d)
{
    if (d == "ppp")
        return 0;
    if (d == "pp")
        return 1;
    if (d == "p")
        return 2;
    if (d == "mp")
        return 3;
    if (d == "mf")
        return 4;
    if (d == "f")
        return 5;
    if (d == "ff")
        return 6;
    if (d == "fff")
        return 7;
    return -1;
}

int main()
{
    // input;
    int n, m;
    cin >> n >> m;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vi notes[8];
    int index = 0;
    int note;
    string d;
    cin >> note >> d;
    int di = toD(d);
    for (int i = 0; i < m - 1; i++)
    {
        cin >> note >> d;
        while (index < note - 1)
        {
            notes[di].push_back(nums[index]);
            index++;
        }
        di = toD(d);
    }
    while (index < n)
    {
        notes[di].push_back(nums[index]);
        index++;
    }

    for (int i = 0; i < 8; i++)
    {
        sort(notes[i].begin(), notes[i].end());
    }
    ll sol = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int nt : notes[i])
            {
                auto it = lower_bound(notes[j].begin(), notes[j].end(), nt);
                int gt = notes[j].end() - it;
                // cout<<gt<<endl;
                sol += gt;
            }
        }
    }

    cout << sol<<"\n";

    return 0;
}