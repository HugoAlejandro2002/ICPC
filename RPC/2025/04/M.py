n, k = map(int, input().split())
sections = []
for _ in range(n):
    sections.append(int(input()))

def check(s):
    print(f'checking s: {s} with l: {l} r: {r}')
    minTrips, maxTrips = 0, 0
    for page in sections:
        # print(f' with page:{page} imma calc')
        mini = (page + s) // (s+1)
        minTrips += mini
        maxTrips += page //s + 1
         
    print(f'checking min <= k <= max: {minTrips} <= {k} <= {maxTrips}')
    return minTrips <= k <= maxTrips

l = 1
r = max(sections)
ans = r
while l <= r:
    mid = (l+r) // 2
    if check(mid):
        ans = mid
        print(f'update asn l {l} r: {mid-1}')
        r = mid - 1
    else:
        l = mid + 1
print(ans)