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

    multiset<int> l, r;

    int n, op, v;
    cin >> n;
    while (n--)
    {
        cin >> op;
        // show(op);
        int ls = l.size(), rs = r.size();
        if (op == 3)
        {
            if (ls == rs)
            {
                if (ls > 0)
                {
                    cout << (*prev(l.end()) + *r.begin()) / 2 << '\n';
                }
                else
                {
                    cout << "Empty!\n";
                }
            }
            else if (ls > rs)
            {
                cout << (*prev(l.end())) << '\n';
            }
            else
            {
                cout << (*r.begin()) << '\n';
            }
        }
        if (op == 1)
        {
            cin >> v;
            if (ls == rs)
            {
                if (ls == 0)
                {
                    r.insert(v);
                }
                else
                {
                    if (v < *r.begin())
                    {
                        l.insert(v);
                    }
                    else
                    {
                        r.insert(v);
                    }
                }
            }
            else if (ls > rs)
            {
                auto pr=prev(l.end());
                if (v >= *pr)
                {
                    r.insert(v);
                }
                else
                {
                    l.erase(pr);
                    r.insert(*pr);
                    l.insert(v);
                }
            }
            else
            {
                auto pr=r.begin();
                if (v <= *pr)
                {
                    l.insert(v);
                }
                else
                {
                    r.erase(pr);
                    l.insert(*pr);
                    r.insert(v);
                }
            }
        }
        if (op == 2)
        {
            cin >> v;
            if (ls >= rs)
            {
                auto it = l.find(v);
                if (it != l.end())
                {
                    l.erase(it);
                }
                else
                {
                    it = r.find(v);
                    if (it != r.end())
                    {
                        r.erase(it);
                        auto pr = prev(l.end());
                        r.insert(*pr);
                        l.erase(pr);
                    }
                }
            }
            else
            {
                auto it = r.find(v);
                if (it != r.end())
                {
                    r.erase(it);
                }
                else
                {
                    it = l.find(v);
                    if (it != l.end())
                    {
                        l.erase(it);
                        auto pr = r.begin();
                        l.insert(*pr);
                        r.erase(pr);
                    }
                }
            }
        }
    }

    return 0;
}