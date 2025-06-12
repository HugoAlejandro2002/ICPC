n = int(input())
nums = list(map(int, input().split()))
s = [0] * 4
res =100000000
for num in nums:
    s[num] +=1
for i in range(4):
    rots = s[(i+1)%4] + 2*s[(i+2)%4] + 3*s[(i+3)%4]
    total = rots + ((4 - (rots + i) % 4) % 4)
    res = min(res, total)
print(res)