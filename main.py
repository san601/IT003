import random


def gen():
    a1 = []
    for i in range(10**6):
        a1.append(random.randint(-10**9, 10**9)/100)
    a1.sort()
    a2 = a1[::-1]

    f = open('test1.inp', 'w')
    for i in range(len(a1) - 1):
        f.write(str(a1[i]) + " ")
    f.write(str(a1[-1]))
    f.close()

    f = open('test2.inp', 'w')
    for i in range(len(a2) - 1):
        f.write(str(a2[i]) + " ")
    f.write(str(a2[-1]))
    f.close()

    for num in range(3, 11):
        a = []
        for j in range(10 ** 6):
            a.append(random.randint(-10 ** 9, 10 ** 9) / 100)
        f = open(f'test{num}.inp', 'w')
        for i in range(len(a) - 1):
            f.write(str(a[i]) + " ")
        f.write(str(a[-1]))
        f.close()


gen()
