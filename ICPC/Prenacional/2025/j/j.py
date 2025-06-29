s = input()

t = [
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
]

mp = {
    "I":[(0,0),(1,1)],
    "l":[(0,1),(1,0)],
    "0":[(2,0),(3,1)],
    "O":[(3,0),(2,1)],
    "8":[(4,0)],
    'B':[(4,1)]
}

for c in s:
    if c in mp.keys():
        for x,y in mp[c]:
            t[x][y] = 1
    
ans = False

for ti in t:
    if ti[0] == ti[1] == 1:
        ans = True

print('SI' if ans else 'NO')