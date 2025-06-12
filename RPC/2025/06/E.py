from collections import Counter
n = input()[::-1]

posible_odds = []

b = 2 

for _ in range(48):
    b = b<<1
    if (b-1) % 3 == 0:
        posible_odds.append((b-1)//3)

MAX = 2<<48

posible_odds = posible_odds[1:]

ans= MAX

def valid(s):
    if s[0] == 'E': return False
    cnt = 0
    curr_c_e = 0
    for c in s:
        if c == 'O':
            cnt+=1
        else:
            curr_c_e = max(curr_c_e,cnt )
            cnt = 0
    curr_c_e = max(curr_c_e,cnt )

    if curr_c_e > 1:
        return False
    
    return True
    
def isPow2(n):
    return n & (n - 1) == 0


def solve(pO):
    ans = pO
    for si in n:
        if si == 'E':
            ans *= 2
            if isPow2(ans): return -1
        else:
            if (ans - 1 ) % 3 == 0:
                ans = ((ans - 1 ) // 3)
            else:
                return -1
    return ans


if valid(n): 
    n = n[1:]
    ans = [solve(pO) for pO in posible_odds]

    ans = [a for a in ans if a != -1]

    if len(ans) > 0:
        print(min(ans))
    else:
        print('INVALID')

    # print(ans)
else:
    print("INVALID")



            







