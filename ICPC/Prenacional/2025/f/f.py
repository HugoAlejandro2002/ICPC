n = int(input())

nums = list(map(int, input().split()))

for i in range(n):
    l = []
    r = []
    l.append(nums[i])
    r.append(nums[2*i])
    print('i', l, r)
    # maxil = -1
    # minir = 100000
    # minir = min(minil, nums[2*i])
    # maxil = max(maxil, nums[i])

    

