from collections import *
from sys import *
from math import *

def sol(n,a):
    for i in range(n):
        if 2*i>=a[i] or 2*(n-i-1)>=a[i]:
            return False
    return True

def main():
    setrecursionlimit(10**7)
    t = int(input())
    for tc in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print('YES' if sol(n,a) else 'NO')

main()