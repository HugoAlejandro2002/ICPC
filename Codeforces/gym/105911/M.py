n,k=map(int,input().split())

if k>n-k:
    for i in range(k):
        print(1,end='')
    for i in range(n-k):
        print(4,end='')
else:
    for i in range(n-k):
        print(2,end='')
    for i in range(k):
        print(3,end='')
