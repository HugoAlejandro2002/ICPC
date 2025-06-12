#include <bits/stdc++.h>
using namespace std;

#define input freopen("I.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define mil6 1000000
#define mil5 100000

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int primes[mil6 + 10];
int superprimes[mil6 + 10];
int varr[mil6 + 10];
int acc[mil6 + 10];
int qarr[mil6 + 10];
int sols[mil5 + 10];
// vi vprimes;
void fp(int x)
{
    // printf("%d: ", x);
    int root = x;
    int countPrimes = 0;
    while (x > 1)
    {
        countPrimes++;
        // acc[primes[x]]++;
        // root *= primes[x];
        for (int j = root*primes[x]; j < mil6 + 1; j *= primes[x])
        {
            superprimes[j] = 0;
        }
        int y = x / primes[x];
        while (primes[y] == primes[x])
        {
            y = y / primes[x];
        }
        x = y;
    }
    superprimes[root] = countPrimes;
    // printf("%d\n", root);
}
// vi acc;
void sieve()
{
    primes[0] = primes[1] = -1;
    for (int i = 2; i < mil6 + 1; i++)
        primes[i] = i;
    for (int i = 2; i < 1000; i++)
    {
        if (primes[i] == i)
        {
            // printf("primo: %d\n", i);
            for (int j = i * i; j < mil6 + 1; j += i)
            {
                primes[j] = i;
            }
        }
    }

    superprimes[0] = superprimes[1] = 0;
    for (int i = 2; i < mil6 + 1; i++)
        superprimes[i] = 1;
    for (int i = 2; i < mil6 + 1; i++)
    {
        if (superprimes[i] > 0)
        {
            printf("superprimo: %d\n", i);
            fp(i);
        }
    }
}


int main()
{
    input;
    int n, q;
    // memset(primes, -1, sizeof primes);
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%d ", primes[i]);
    // }
    // memset(varr, 0, sizeof varr);
    sieve();
    memset(qarr, 0, sizeof qarr);
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        // fp(v[i]);
        varr[v[i]] = 1;
    }
    // printf("hola antes\n");

    for (int p = 2; p < mil6 + 1; p++)
    {
        // printf("%d ", vprimes[p]);
        int ac = 0;
        if (superprimes[p])
            for (int i = p; i < mil6 + 1; i += p)
            {
                ac += varr[i];
            }
        acc[p] = ac;
    }

    for (int i = 0; i < 100; i++)
    {
        printf("%d ", acc[i]);
    }
    printf("\n\n");

    // printf("\n\n");
    for (int p = 2; p < mil6 + 1; p++)
    {
        if (superprimes[p] > 0 && acc[p] > 0)
        {
            int sign = superprimes[p] % 2 ? 1 : -1;
            for (int i = p; i < mil6 + 1; i += p)
                qarr[i] += acc[p] * sign;
        }
        // printf("%d ", acc[p]);
    }
    // printf("\n\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", qarr[i]);
    }
    printf("\n\n");

    sols[0] = 1;
    for (int i = 1; i < mil5 + 1; i++)
    {
        sols[i] = (2 * sols[i - 1]) % 1000000007;
    }

    scanf("%d", &q);
    int x;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        // print sol
        printf("%d\n", sols[n - qarr[x]]);
    }

    return 0;
}