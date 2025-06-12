t=int(input())
for _ in range(t):
    a,b,c=input().split()

    if b==c or (len(a)==2 and ((b==a and c==a[::-1]) or (b==a[::-1] and c==a))):
        print(1)
    else:
        print(0)