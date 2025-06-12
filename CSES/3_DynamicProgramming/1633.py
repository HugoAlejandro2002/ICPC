n = int(input())
dp = [0] * (n + 6)
MOD = 10**9 + 7

for i in range(1, 7):
    dp[i]=1
for i in range(1, n):
    for j in range(1,7):
        dp[i+j]=(dp[i+j]+dp[i])%MOD

print(dp[n])
