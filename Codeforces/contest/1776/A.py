t=int(input())

for tc in range(t):
    n=int(input())
    nums=list(map(int,input().split()))
    nums.append(1440)
    walks=0
    for i in range(0,n+1):
        if i==0:
            walks+=nums[i]//120
        else:
            walks+=(nums[i]-nums[i-1])//120

    print('YES' if walks>=2 else 'NO')