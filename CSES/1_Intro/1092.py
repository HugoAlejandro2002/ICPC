n=int(input())

if n%4==0:
    print('YES')
    nums=[[],[]]
    for i in range(1,n//2+1):
        nums[i%2].append(i)
        nums[i%2].append(n+1-i)
    print(n//2)
    for num in nums[0][:-1]:
        print(num, end=' ')
    print(nums[0][-1])
    print(n//2)
    for num in nums[1][:-1]:
        print(num, end=' ')
    print(nums[1][-1])
elif n%4==3:
    print('YES')
    nums=[[],[]]
    for i in range(1,n//2+1):
        nums[i%2].append(i)
        nums[i%2].append(n-i)
    nums[0].append(n)
    print(n//2)
    for num in nums[0][:-1]:
        print(num, end=' ')
    print(nums[0][-1])
    print(n//2+1)
    for num in nums[1][:-1]:
        print(num, end=' ')
    print(nums[1][-1])
else:
    print('NO')
    