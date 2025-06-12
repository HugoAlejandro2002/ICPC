q = int(input())

for tc in range(q):
    nums = list(map(int, input().split()))
    lnums=nums.pop(0)
    # nums.sort(reverse=True)

    isin = [False for i in range(61)]
    for num in nums:
        isin[num] = True

    for i in range(60, -1, -1):
        if isin[i]:
            sol = 2**i-1
            ni = i
            break

    for i in range(ni, 0, -1):
        if not isin[i]:
            sol -= 2**(i-1)
    
    print(sol)
        

