#include <bits/stdc++.h>
using namespace std;

#define input freopen("K.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x, y) cout << #x << " = " << x << ", " << #y << " =" << y << endl
#define show3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int nums[101];
int dp[101][100010];
int path[101][100010];

int subsetSum(int n, int sum)
{
    if (sum == 0)
        return 1;

    if (n <= 0)
        return 0;

    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];

    if (nums[n - 1] > sum)
    {
        bool res = subsetSum(n - 1, sum);
        if (res)
        {
            path[n - 1][sum] = 0;
        }
        return dp[n - 1][sum] = res;
    }
    else
    {
        bool res0 = subsetSum(n - 1, sum);
        if (res0)
        {
            path[n - 1][sum] = 0;
            return dp[n - 1][sum] = res0;
        }
        bool res1 = subsetSum(n - 1, sum - nums[n - 1]);
        if (res1)
        {
            path[n - 1][sum] = 1;
        }
        return dp[n - 1][sum] = res1;
    }
}

int main()
{
    // input;
    int n, sum = 0;
    memset(dp, -1, sizeof dp);
    memset(path, -1, sizeof path);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    // printf("hola %d\n", sum);
    if (sum % 2 == 0 && subsetSum(n, sum / 2))
    {
        // printf("hola after\n");
        vi first, second;
        int acc = sum / 2;
        for (int i = n - 1; i >= 0; i--)
        {
            if (path[i][acc]==1)
            {
                first.push_back(nums[i]);
                acc -= nums[i];
            }
            else
            {
                second.push_back(nums[i]);
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < 10; j++)
        //     {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < 10; j++)
        //     {
        //         printf("%d ", path[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        int a=0,b=0;
        int as=0,bs=0;
        for (int i = 0; i < n; i++)
        {
            if (bs>as){
                printf("%d ", first[a]);
                as+=first[a];
                a++;
            } else {
                printf("%d ", second[b]);
                bs+=second[b];
                b++;
            }
        }
    } else {
        printf("-1");
    }
    // printf("hola after all\n");
    return 0;
}