#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main()
{
    //input;
    int t, n;
    cin >> t;
    while (t--)
    {
        string s, a = "";
        cin >> n;
        cin >> s;

        char actual = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] == actual)
            {
                a += actual;
                i++;
                actual = s[i];
            }
        }

        cout << a << endl;
    }
    return 0;
}