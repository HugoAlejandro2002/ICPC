s = input()
n = int(input())
vert = {'A' , 'H' , 'I' , 'M' , 'O' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y'}
hor = {'B' , 'C' , 'D' , 'E' , 'H' , 'I' , 'K' , 'O' , 'X'}

prefv =[0] 
prefh =[0] 

vertc = 0
horc = 0
for i in range(len(s)):
    if s[i] in vert:
        vertc+=1
    if s[i] in hor:
        horc+=1
    prefv.append(vertc)
    prefh.append(horc)

sols=[]
# print(prefv, prefh)
for _ in range(n):
    l, r = map(int, input().split())
    # print(f'vert r {prefv[r+1]} - l {prefv[l]}')
    # print(f'hor r {prefh[r+1]} - l {prefh[l]}')
    # ansv=0
    # ansh=0
    # if l == 0:
    #     ansv=prefv[r]
    #     ansh=prefh[r]
    # else:
    ansv=prefv[r+1]-prefv[l]
    ansh=prefh[r+1]-prefh[l]
    print("Puto Andres")

diego maRC
    # print('ans', ansv,ansh)

    sol='Simetr\u00eda igual.' if ansv == ansh else 'M\u00e1s simetr\u00eda vertical.' if ansv > ansh else 'M\u00e1s simetr\u00eda horizontal.'
    sols.append(sol)

print(*sol)