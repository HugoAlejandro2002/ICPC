import sys
from collections import deque

def main():
    sys.setrecursionlimit(1 << 25)
    input = sys.stdin
    t = int(input.readline())
    results = []
    
    for _ in range(t):
        n = int(input.readline())
        l = []
        r = []
        for _ in range(n):
            li, ri = map(int, input.readline().split())
            l.append(li)
            r.append(ri)
        
        adj = [[] for _ in range(n)]
        for _ in range(n-1):
            u, v = map(int, input.readline().split())
            u -= 1
            v -= 1
            adj[u].append(v)
            adj[v].append(u)
        
        # Binary search parameters
        low = max(l)
        high = max(r) + 10**6
        answer = high
        
        while low <= high:
            mid = (low + high) // 2
            x_min = [max(mid - r[i], 0) for i in range(n)]
            x_max = [mid - l[i] for i in range(n)]
            
            valid = True
            for i in range(n):
                if x_min[i] > x_max[i]:
                    valid = False
                    break
            if not valid:
                low = mid + 1
                continue
            
            x = x_min.copy()
            q = deque()
            in_queue = [False] * n
            for i in range(n):
                q.append(i)
                in_queue[i] = True
            
            valid = True
            while q and valid:
                u = q.popleft()
                in_queue[u] = False
                for v in adj[u]:
                    if x[u] < x[v]:
                        new_xu = max(x[u], x[v])
                        if new_xu > x_max[u]:
                            valid = False
                            break
                        if new_xu != x[u]:
                            x[u] = new_xu
                            for w in adj[u]:
                                if not in_queue[w]:
                                    q.append(w)
                                    in_queue[w] = True
                if not valid:
                    break
            
            if valid:
                for i in range(n):
                    if x[i] > x_max[i]:
                        valid = False
                        break
            if valid:
                answer = mid
                high = mid - 1
            else:
                low = mid + 1
        
        results.append(answer)
    
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()