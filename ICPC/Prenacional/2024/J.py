def gcd(a, b):
    while b != 0:
        t = b
        b = a % b
        a = t
    return a

def super_alfil_formula_adjusted(n, m):
    r = gcd(n - 1, m - 1)
    a = (n - 1) // r
    b = (m - 1) // r
    term1 = b * (n - 1)
    term2 = 1
    term3 = (a - 1) * (b - 1) // 2
    correction = term1 + term2 - term3
    
    visited_casillas = n * m - correction
    return int(visited_casillas)

from sys import stdin
# with open('J.txt', 'r') as stdin:
while True:
    line = stdin.readline()
    if not line:
        break
    n, m = map(int, line[:-1].split())
    # n, m = map(int, input().split())
    print(super_alfil_formula_adjusted(n, m))