t = int(input())
for i in range(t):
    n = int(input())
    i = 1
    v = 0
    for p in range(n):  
        s = ''
        j = 1
        for q in range(n):
                s += str(i) + ' '
                i += j
                j += 1
        print(s)
        v += 1
        m += 1