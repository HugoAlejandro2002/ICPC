n=int(input())
sol=0
for i in range(1,13):
    sol+=n//(5**i)
print(sol)