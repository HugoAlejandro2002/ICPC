from collections import *
from sys import *
from math import *

def sol(s):
    return len(list(filter(lambda c: c=='1', s)))

def main():
    setrecursionlimit(10**7)
    t = int(input())
    for tc in range(t):
        s = input()
        print(sol(s))

main()