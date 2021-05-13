l = list(map(int, input().split()))
m = l[0]
j = 0
for i in range(4):
    if(l[i]>m):
        m = l[i]
        j = i
del l[j]

for i in range(3):
    print(m-l[i], end=' ')
    