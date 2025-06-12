from collections import *
from sys import *
from math import *

if __name__ == "__main__":
    setrecursionlimit(10**7)
    main()

def main_m():
    with open('P.txt','r') as stdin:
        n,m = map(int, stdin.readline()[:-1].split())
        G = [list(stdin.readline()[:-1]) for _ in range(n)]
        ans = sol(n,m,G)
        print(ans)

def main_a():
    with open('D.txt','r') as stdin:
        n,m = map(int, stdin.readline()[:-1].split())

        G = [[] for _ in range(n+1)]
        for _ in range(m):
            a,b = map(int, stdin.readline()[:-1].split())
            G[a].append(b)
            G[b].append(a)

        ans = sol(n,G)


def sol(m,n,G):
    ans = 0
    visited_m = [[False for _ in range(n)] for _ in range(m)]                
    visited_a = [False for _ in range(n+1)]

    def bfs(x,y):
        q = deque([(x,y)])
        while q:
            x,y = q.popleft()
            for dx,dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                nx,ny = x+dx,y+dy
                if 0<=nx<m and 0<=ny<n and G[nx][ny] != '#':
                    G[nx][ny] = '#'
                    q.append((nx,ny))

    def dfs(x,y):
        visited[x][y] = True
        for dx,dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx,ny = x+dx,y+dy
            if 0<=nx<m and 0<=ny<n and not visited[nx][ny]:
                dfs(nx,ny)

    def bfs(ini):
        q = deque([ini])
        visited[ini] = True
        while q:
            act = q.popleft()
            for next in G[act]:
                if not visited[next]:
                    visited[next] = True
                    q.append(next)

    def dfs(ini):
        visited[ini] = True
        for next in G[ini]:
            if not visited[next]:
                dfs(next)

    return ans
