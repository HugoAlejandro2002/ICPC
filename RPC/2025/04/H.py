g, r = map(int,input().split())

if r >= g:
    print(g * 10)
else:
    ans = 0 
    ans += (r *10)
    g-=r

    tg = (g//3)
    ans += (tg*10)
    g = g % 3
    dg = (g//2)
    ans += (dg*3)
    g = g % 2
    ans += g
    print(ans)
    
