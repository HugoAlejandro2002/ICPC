import math as m

t=int(input())

for tc in range(t):
    A,B,C,L,R = map(int, input().split())

    f = lambda x: A*x**2+B*x+C

    fi = lambda x: 2*A*x**3 + 3*B*x**2 + 6*C*x
    pmin = -B/(2*A)

    pfloor = m.floor(pmin)
    pceil = m.ceil(pmin)

    # print(pmin)

    va_arriba = A>0

    if L >= pmin:
        # busqueda binaria L hasta R derecha
        # print('caso1')
        izq = L
        der = R
        sol = -1
        while izq<=der:
            ev=(izq+der)//2
            res = f(ev)
            if res<0:
                if va_arriba:
                    izq=ev+1
                else: 
                    der=ev-1
            elif res>0:
                if va_arriba:
                    der=ev-1
                else: 
                    izq=ev+1
            else:
                sol = abs(fi(ev)-fi(L))+abs(fi(R)-fi(ev))
                break
        if sol==-1:
            sol = abs(fi(R)-fi(L))

    elif R<= pmin:
        # print('caso2')
        izq = L
        der = R
        sol = -1
        while izq<=der:
            ev=(izq+der)//2
            res = f(ev)
            if res<0:
                if not va_arriba:
                    izq=ev+1
                else: 
                    der=ev-1
            elif res>0:
                if not va_arriba:
                    der=ev-1
                else: 
                    izq=ev+1
            else:
                sol = abs(fi(ev)-fi(L))+abs(fi(R)-fi(ev))
                break
        if sol==-1:
            sol = abs(fi(R)-fi(L))
    else:
        # busqueda binaria L pmin y pmin a R
        # print('caso3')
        izq = L
        der = pfloor
        sol = -1
        while izq<=der:
            ev=(izq+der)//2
            res = f(ev)
            if res<0:
                if not va_arriba:
                    izq=ev+1
                else: 
                    der=ev-1
            elif res>0:
                if not va_arriba:
                    der=ev-1
                else: 
                    izq=ev+1
            else:
                sol = abs(fi(ev)-fi(L))+abs(fi(pfloor)-fi(ev))
                break
        if sol==-1:
            sol = abs(fi(pfloor)-fi(L))

        izq = pceil
        der = R
        sol2 = -1
        while izq<=der:
            ev=(izq+der)//2
            res = f(ev)
            if res<0:
                if va_arriba:
                    izq=ev+1
                else: 
                    der=ev-1
            elif res>0:
                if va_arriba:
                    der=ev-1
                else: 
                    izq=ev+1
            else:
                sol2 = abs(fi(ev)-fi(pfloor))+abs(fi(R)-fi(ev))
                break
        if sol2==-1:
            sol2 = abs(fi(R)-fi(pfloor))

        sol = sol + sol2

    gc = m.gcd(sol, 6)

    print(f"{sol//gc}/{6//gc}")