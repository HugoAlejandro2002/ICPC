from collections import *
from sys import *
from math import *

setrecursionlimit(10**7)

def main():
    with open('in.txt','r') as stdin:
        n,m = map(int, stdin.readline()[:-1].split())
        G = [list(stdin.readline()[:-1]) for _ in range(n)]
        ans = sol(n,m,G)
        print(ans)

def sol(n,m,G):
    return 0