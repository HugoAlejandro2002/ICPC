n=int(input())
sol=1
for i in range(n):
    sol=int((sol*2)%(1e9+7))
print(sol)