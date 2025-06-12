w=input()
freq={}
for c in w:
    if c not in freq:
        freq[c]=1
    else:
        freq[c]+=1

nw=''

last=None
for c,f in freq.items():
    if f&1:
        if last:
            print('NO SOLUTION')
            exit(0)
        else:
            last=(c,f)
    else:
        nw+=c*(f//2)

if last:
    print(nw+last[0]*last[1]+nw[::-1])
else:
    print(nw+nw[::-1])