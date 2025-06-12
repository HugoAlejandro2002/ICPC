criba = [True for i in range(100001)]
criba[0] = False
criba[1] = False

for i in range(2,320):
    if(criba[i]):
        for j in range(i*i, 100001, i):
            criba[j] = False

# for i in criba[:100]:
#     print(i)

n=int(input())

sol = ""
for p in range(2,n+1):
    if (criba[p]):
        while n%p==0:
            sol+=str(p)+'x'
            n/=p
    if n==1:
        break

print(sol[:-1])