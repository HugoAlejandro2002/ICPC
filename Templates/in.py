from random import randint

with open("in.txt", "w") as f:
    n = 1000
    f.write(str(n))
    for i in range(n):
        f.write(f" {i+1}")
    # f.write("300000 100000 300000\n")
    # f.write('abc'*100000+"\n")

    # for _ in range(300000):
    #     a = randint(1, 300000)
    #     b = randint(a, 300000)
    #     f.write(f"{a} {b}\n")