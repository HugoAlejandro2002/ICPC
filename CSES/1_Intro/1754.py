t=int(input())

for _ in range(t):
    a,b=map(int,input().split())
    mi = min(a,b)
    ma = max(a,b)

    res=2*mi-ma
    if res>=0 and res%3==0:
        print('YES')
    else:
        print('NO')

    