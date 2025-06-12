t=int(input())

for _ in range(t):
    y,x=map(int,input().split())
    if x>y:
        if x&1:
            print(x**2-y+1)
        else:
            print(x**2-2*x+1+y)
    elif y>x:
        if y&1:
            print(y**2-2*y+1+x)
        else:
            print(y**2-x+1)
    else:
        print(x**2-x+1)

    

    