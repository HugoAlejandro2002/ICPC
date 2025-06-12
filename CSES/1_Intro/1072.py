n=int(input())

sol=[0,6,28,96]
for i in range(5,n+1):
    sol.append(sol[i-2]+2*(i-5)*((i-1)**2-4)+8*(i-1)**2-20+(i-1)**2-2+(2*i-1)*(i-1)-2)
for i in range(n):
    print(sol[i])

    