from collections import *
from sys import *
from math import *

def sol(n,a):
    if len(a)==1:
        return a[0]
    max_sum = sum(a)
    while len(a)!=1:
        # print(len(a))
        new_a = []
        for i in range(1,len(a)):
            # print(a[i], a[i-1])
            new_a.append(a[i]-a[i-1])
        a=new_a
        max_sum = max(max_sum, abs(sum(a)))
    max_sum = max(max_sum, abs(sum(a)))
    return max_sum

def main():
    setrecursionlimit(10**7)
    t = int(input())
    for tc in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(sol(n,a))

main()