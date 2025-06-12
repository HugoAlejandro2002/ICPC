import math as m
res=0
# for i in range(100001):
#     res+=int(m.sqrt(i))
# print(res)

for i in range(2,int(m.sqrt(305000))):
    for j in range(i*i, 305000, i):
        res+=1

print(res)