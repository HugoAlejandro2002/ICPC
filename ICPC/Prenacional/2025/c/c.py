n=int(input())

a=list(map(int,input().split()))
b=list(map(int,input().split()))

gr=1
result=True
for i in range(1,n):
    if a[i] ==a[i-1]:
        gr+=1
    else:
        if gr==1:
            result=False
            break
        else:
            gr=1
for i in range(1,n):
    if b[i] ==b[i-1]:
        gr+=1
    else:
        if gr==1:
            result=False
            break
        else:
            gr=1

print('SI' if result else 'NO')