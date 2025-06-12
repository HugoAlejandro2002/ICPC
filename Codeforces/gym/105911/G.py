import math
n,m,q = map(int, input().split())
graf = [[] for _ in range(n+1)]
for i in range(m):
    a,b,w= map(int, input().split())
    graf[a].append((b, w))

for t in range(q):
    ini, stat= map(int, input().split())
    prev = ini
    c = 0
    while stat > 0:
        curr = graf[prev]
        
        maxi = curr[0][1]
        prev = curr[0][0]
        if len(curr) != 1:
            for edge in curr:
                if edge[1] > maxi:
                    prev = edge[0]
                    maxi = edge[1]
                    
                # maxi = max(maxi, edge[1])
                
        # print(f'stat {stat} changed to {math.floor(stat/maxi)}')
        stat = math.floor(stat / maxi)
        c+=1
        
        # print(stat)
    # print(f'res {t+1}: {c}')
    print(c)
    # print(stat)

# print(graf)
