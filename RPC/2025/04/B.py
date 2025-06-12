x1, y1, x2 , y2 = map(int,input().split())
p1 = (x1,y1)
p2 = (x2,y2)
pmi = min(p1,p2)
pma = max(p1,p2)

if pmi == (0,0) and pma == (2024,2024):
    print(0)
elif pmi == (0,2024) and pma == (2024,0):
    print(0)
elif pmi == (0,2024) or pmi== (0, 0):
    print(1)
elif pma == (2024,2024) or pma== (2024,0):
    print(1)
else:
    print(2)