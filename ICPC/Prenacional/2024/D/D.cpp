#include <bits/stdc++.h>
using namespace std;

#define input freopen("D.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main()
{
    // input;

    int n, x;
    vi res(305000, 1);
    cin>>n;
    // memset(res, 1, sizeof res);

    res[0] = 0;
    res[1] = 0;

    for (int i = 2; i * i < 305000; i++)
    {
        for (int j = i * i; j < 305000; j += i)
        {
            res[j] += i;
            if (i * i != j)
            {
                res[j] += (j / i);
            }
        }
    }   

    // int mas = 0;
    // for (int ri = 0; ri < 100001; ri++)
    // {
    //     // if(res[ri]>100000)
    //     //     printf("%d: %d\n", ri, res[ri]);
    //     if (res[ri]>mas){
    //         mas=res[ri];
    //     }
    // }

    // show(mas);
    

    while (n--)
    {
        cin>>x;
        if (res[x] == x)
        {
            printf("%d perfecto\n", x);
        }
        else if (res[res[x]] == x)
        {
            printf("%d romantico", x);
            if (res[x] > x)
            {
                printf(" abundante");
            }
            printf("\n");
        }
        else if (res[x] > x)
        {
            printf("%d abundante\n", x);
        }
        else
        {
            printf("%d complicado\n", x);
        }

    }
    return 0;
}
