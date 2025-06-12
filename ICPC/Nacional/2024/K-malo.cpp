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

int n;
int dp[201][101];
int used[201][101][101];
int nums[101];

int solve(int diff, int st, int index)
{
    int diffOp = diff - 100;
    printf("diff: %d, st: %d, index: %d\n", diffOp, st, index);
    if (dp[diff][st] != -1)
    {
        return dp[diff][st];
    }

    if (st == 0)
    {
        if (diffOp == 0)
        {
            return index;
        }
        return -2;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[diff][st + 1][i] || i == index)
        {
            used[diff][st][i] = 1;
        }
        else
        {
            used[diff][st][i] = 0;

            if (abs(diffOp) > nums[i])
            {
                int res = solve(diffOp > 0 ? (diff - nums[i]) : (diff + nums[i]), st - 1, i);
                if (res != -2)
                    return dp[diff][st] = i;
            }
            else if (diffOp == nums[i])
            {
                int res = dp[diff][st] = solve(100, st - 1, i);
                if (res != -2)
                    return dp[diff][st] = i;
            }
            else if (diffOp == 0)
            {
                int first = solve(diff + nums[i], st - 1, i);
                if (first != -2)
                    return dp[diff][st] = i;

                int second = solve(diff - nums[i], st - 1, i);
                if (second != -2)
                    return dp[diff][st] = i;
            }
        }
    }
    return -2;
}

int main()
{
    input;
    memset(dp, -1, sizeof dp);
    memset(used, 0, sizeof used);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    vi sols;
    int diff = 100;
    int sol = solve(diff, n, -1);
    for (int j = n+1; j >= 0; j--)
    {
        for (int i = 95; i < 105; i++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    if (sol != -2)
    {
        for (int i = 1; i <= n; i++)
        {
            sols.push_back(sol);
            if (diff != 100)
            {
                sol = dp[diff > 100 ? (diff=(diff - nums[sol])) : (diff=(diff + nums[sol]))][n - i];
            }
            else
            {
                sol = dp[diff - nums[sol]][n - i] >= 0 ? dp[diff=(diff - nums[sol])][n - i] : dp[diff=(diff + nums[sol])][n - i];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%d ", sols[i]);
        }
    }
    else
    {
        printf("-1");
    }

    return 0;
}