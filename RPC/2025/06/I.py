t=int(input())
for _ in range(t):
    code=input()
    l=len(code)
    valid=True

    h=0
    prev=False
    nums=[]
    for i in range(l-1):
        if code[i]=='X':
            valid=False
            break
        if code[i]=='-':
            if prev:
                valid=False
                break

            prev=True
            h+=1
            if i==0:
                valid=False
                break
            if h>3:
                valid=False
                break
            if h==3 and i!=l-2:
                valid=False
                break
            continue

        prev=False
        nums.append(int(code[i]))

    check=-1
    if code[-1]=='-':
        valid=False
    else:
        check = 10 if code[-1]=='X' else int(code[-1])
    nl=len(nums)
    sumn=0
    if nl==9:
        for i in range(nl):
            sumn+=(10-i)*nums[i]
        sumn+=check

        if not sumn%11==0:
            valid=False
    else:
        valid=False

    if valid:
        sumn = 9+3*7+8
        for i in range(nl):
            sumn+=nums[i]+2*(1-i&1)*nums[i]
        new_check=(10-sumn)%10
        print('978-'+code[:-1]+str(new_check))
    else:
        print('invalid')
