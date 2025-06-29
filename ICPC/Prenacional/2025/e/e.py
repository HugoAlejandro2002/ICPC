n,x = map(int,input().split())
c=list(map(int,input().split()))

dp = [-1] * (x + 1)

for ci in c:
    if ci>x: continue
    dp[ci]=1
for i in range(1, x):
    if dp[i]==-1: continue
    for ci in c:
        if i+ci>x: continue
        if dp[i+ci]==-1:
            dp[i+ci]=dp[i]+1
        else:
            dp[i+ci]=max(dp[i+ci], dp[i]+1)

print(dp[x])
