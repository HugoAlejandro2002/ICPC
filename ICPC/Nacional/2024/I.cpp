#include <bits/stdc++.h>
using namespace std;

#define input freopen("I.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

ll primes[1000010];
ll primesFact[1000010];
ll varr[1000010];
ll acc[1000010];
ll qarr[1000010];
int sols[100010];
// vi vprimes;
// vi acc;
void sieve()
{
    primesFact[0] = primesFact[1] = -1;
    for (int i = 2; i < 1000001; i++)
        primesFact[i] = i;
    for (int i = 2; i < 1000; i++)
    {
        if (!primes[i])
        {
            // vprimes.push_back(i);
            // printf("primo: %d\n", i);
            for (int j = i * i; j < 1000001; j += i)
            {
                primesFact[j] = i;
                if (primes[j] < 2)
                {
                    if (j % (i * i) == 0)
                    {
                        primes[j] = 2;
                    }
                    else
                        primes[j] = 1;
                }
            }
        }
    }
}

pii fp(int x)
{
    // printf("%d: ", x);
    int root = 1;
    int countPrimes = 0;
    while (x > 1)
    {
        root*=primesFact[x];
        countPrimes++;
        int y = x / primesFact[x];
        while (primesFact[y] == primesFact[x])
        {
            y = y / primesFact[x];
        }
        x = y;
    }
    // superprimes[root] = countPrimes;
    // printf("%d\n", root);
    return {root, countPrimes};
}

int main()
{
    // input;
    int n, q;
    memset(primes, 0, sizeof primes);
    memset(varr, 0, sizeof varr);
    memset(qarr, 0, sizeof qarr);
    primes[0] = primes[1] = 2;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        // printf("in: %d\n", v[i]);
        varr[v[i]] += 1;
    }

    // printf("\nhola antes\n");
    sieve();
    // for (int i = 0; i < 1000001; i++)
    // {
    //     if (primes[i]<2)
    //     printf("%d ", i);
    // }
    // printf("\n\n");

    // printf("prime1: %d, ", primesFact[245438]);
    // printf("prime2 %d\n", primesFact[400422]);

    for (int p = 2; p < 1000001; p++)
    {
        // printf("%d ", vprimes[p]);
        if (primes[p]<2){
            ll ac = 0;
            for (int i = p; i < 1000001; i += p)
            {
                ac += varr[i];
            }
            acc[p] = ac;
        }
    }

    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%d ", acc[i]);
    // }
    // printf("\n\n");

    // printf("\n\n");
    for (int p = 2; p < 1000001; p++)
    {
        if (primes[p] < 2) {
            int prim_count = fp(p).second;
            // printf("superprime: %d => %d\n", p, prim_count);
            int sign = prim_count % 2 ? 1 : -1;
            for (int i = p; i < 1000001; i += p)
                qarr[i] += acc[p]*sign;
        }
        // printf("%d ", acc[p]);
    }
    // printf("\n\n");
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%d ", qarr[i]);
    // }
    // printf("\n\n");

    sols[0] = 1;
    for (int i = 1; i < 100001; i++)
    {
        sols[i] = (2 * sols[i - 1]) % 1000000007;
        // printf("%d\n",sols[i]);
    }

    scanf("%d", &q);
    int x;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        // print sol
        printf("%d\n", sols[n - qarr[fp(x).first]]);
    }

    return 0;
}