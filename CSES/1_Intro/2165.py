def hanoi(n, s, t):
    if n==1:
        return [(s, t)]
    
    if (n,s,t) in dp:
        return dp[(n,s,t)]
    
    pos = [-1,0,0,0]
    pos[s] = pos[t] = 1
    e = pos.index(0)

    dp[(n,s,t)] = hanoi(n-1,s,e) + [(s,t)] + hanoi(n-1,e,t)
    return dp[(n,s,t)]

dp = {}
n = int(input())
res = hanoi(n,1,3)
print(len(res))
for s,t in res:
    print(s,t)
