n,x = map(int,input().split())
c=list(map(int,input().split()))

MOD=10**9+7

dp = [0] * (x + 1)

for ci in c:
    if ci>x: continue
    dp[ci]=1
for i in range(x):
    if dp[i]==0: continue
    for ci in c:
        if i+ci>x: continue
        dp[i+ci]=(dp[i+ci]+dp[i])%MOD

# print(dp)
print(dp[x])
