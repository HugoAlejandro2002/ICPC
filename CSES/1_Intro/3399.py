t=int(input())
for tc in range(t):
    n,a,b=map(int,input().split())
    if a+b>n:
        print('NO')
        continue
    if a!=b and (a==0 or b==0):
        print('NO')
        continue

    mi=min(a,b)
    ma=max(a,b)
    eq=n-a-b
    less=list(range(1,n+1))
    more=[]
    for i in range(ma):
        more.append(i+1+mi)
    for i in range(mi):
        more.append(i+1)
    for i in range(eq):
        more.append(i+n-eq+1)
    print('YES')
    if a>b:
        print(' '.join(map(str,more)))
        print(' '.join(map(str,less)))
    else:
        print(' '.join(map(str,less)))
        print(' '.join(map(str,more)))
