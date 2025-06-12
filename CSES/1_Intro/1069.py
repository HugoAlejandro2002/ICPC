w=input()
sol=0
last=None
crr=0
for c in w:
    if c==last:
        crr+=1
    else:
        sol=max(sol,crr)
        crr=0
        last=c

sol=max(sol,crr)
print(sol+1)