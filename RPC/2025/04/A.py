r,c=map(int,input().split())

odd=0
for line in range(r):
    w=input()
    b=c-len(w)
    if b%2==1:
        odd+=1
        if odd%2==1:
            l=b//2
            r=l+1
        else:
            r=b//2
            l=r+1
    else:
        l=b//2
        r=l
    print('.'*l+w+'.'*r)
