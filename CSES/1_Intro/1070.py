n=int(input())
if n==1:
    print(1)
elif n<4:
    print("NO SOLUTION")
else:
    l=[]
    for i in range(n):
        if i%2:
            l.append(str((i+1)//2))
        else:
            l.append(str(i//2+n//2+1))
    print(' '.join(l))