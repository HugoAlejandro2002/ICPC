n,k = map(int, input().split())

nums = list(map(int, input().split()))
sumi = sum(nums)
c=0
for num in nums:
    ke = sumi - num
    if ke % k == 0:
        c+=1
print(c,end="")

