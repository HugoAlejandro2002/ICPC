t=int(input())
for tc in range(t):
    n,k=map(int,input().split())
    r=[-1]*(n+1)
    c=[-1]*(n+1)

    r[0],c[0],p,L,R=map(float,input().split())

    for i in range(k):
        ri,vi=map(float,input().split())
        r[int(ri)]=vi

    for i in range(1,n+1):
        if r[i]==-1:
            r[i]=L
        c[i]=p*c[i-1]+(1-p)*r[i-1]

    sol=0
    for i in range(1,n+1):
        sol+=c[i]-r[i]

    print(sol)
    
