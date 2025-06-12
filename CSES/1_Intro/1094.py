n=int(input())
nums=list(map(int,input().split()))

sol=0
last=nums[0]
for i in range(1,n):
    if nums[i]<last:
        sol+=last-nums[i]
    else:
        last=nums[i]

print(sol)
