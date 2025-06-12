n=int(input())

cards = [0]*(2*n+1)
for i in range(n):
    cards[int(input())]=1

a=[]
b=[]

for i in range(1,2*n+1):
    if cards[i]:
        a.append(i)
    else:
        b.append(i)

a.sort()
b.sort()

# print(a)
# print(b)

va=[0]*(2*n+1)
vb=[0]*(2*n+1)

for ca in a:
    for cb in b:
        if ca>cb and not vb[cb]:
            vb[cb]=1
            break

for cb in b:
    for ca in a:
        if cb>ca and not va[ca]:
            va[ca]=1
            break

# print(va)
# print(vb)

print(n-sum(va),sum(vb))