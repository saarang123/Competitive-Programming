s = list(map(int, input().split()))
n = s[0]
t = s[1]
del s[0:2]
a1 = []
count = 0
for i in range(n):
    for j in range(0, i):
        a1.append([(s[i]+s[j]),(i, j)])
print(a1)
for p in range(len(a1)):
    for q in range(0, p):
        for ij in a1[p][1]:
            if ij in a1[q][1]:
                break
        if (a1[p][0] + a1[q][0] == t):
            count+=1
            print(a1[p][0], a1[q][0])
print(count)
                    
                    
                    
                        