n=int(input())
S=set(range(1,n+1))
nums=set(map(int,input().split()))
print(S.difference(nums).pop())