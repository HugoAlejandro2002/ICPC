# Use to generate large test cases
from random import randint

MAXN=300000

with open("in.txt", "w") as f:
    n = 1000
    f.write(str(n))
    for i in range(n):
        f.write(f" {i+1}")
    f.write("300000 100000 300000\n")
    f.write('abc'*100000+"\n")

    for _ in range(MAXN):
        a = randint(1, MAXN)
        b = randint(a, MAXN)
        f.write(f"{a} {b}\n")