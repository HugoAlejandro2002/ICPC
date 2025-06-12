from sys import stdin
from collections import deque

# stdin = open('in.txt','r')

r,c = map(int,stdin.readline().split())

nut = int(stdin.readline(),2)
nut1 = nut

nut1_arr = [0]*c
for i in range(c):
    nut1_arr[i] = nut1
    first_bit = nut1 & (1<<c-1)
    nut1 = ((nut1^first_bit)<<1) + int(first_bit!=0)


nut2 = 0
for i in range(c):
    if 1<<i & nut:
        nut2+=1<<c-i-1

nut2_arr = [0]*c
for i in range(c):
    nut2_arr[i] = nut2
    first_bit = nut2 & (1<<c-1)
    nut2 = ((nut2^first_bit)<<1) + int(first_bit!=0)



# print(nut1_arr)
# print(nut2_arr)

rows = [0]*r
for i in range(r):
    rows[i] = int(stdin.readline(),2)

# print(rows)
    


def solve_maze(nut_arr):
    directions = [(1,0),(0,1),(0,-1),(-1,0)]
    maze = [[False for i in range(c)] for i in range(r)]
    # visit = [[False for i in range(c)] for i in range(r)]

    cola = deque()

    for i in range(c):
        maze[0][i] = nut_arr[i] & rows[0] != 0
        if not maze[0][i]:
            if r==1: return True
            cola.append((0,i))

    # print(maze)
    
    while cola:
        y,x = cola.popleft()
        maze[y][x] = True

        for d in directions:
            dx = x+d[0]
            dy = y+d[1]

            if dx<0: dx=c-1
            elif dx==c: dx=0

            if dy>=0 and dy<r and not maze[dy][dx]:
                if nut_arr[dx] & rows[dy] == 0:
                    # print(dy,dx)
                    # print(maze)
                    if dy == r-1:
                        return True
                    cola.append((dy,dx))
                else:
                    maze[dy][dx] = True

    # print(maze)
    return False
    


print('Y' if solve_maze(nut1_arr) or solve_maze(nut2_arr) else 'N')
