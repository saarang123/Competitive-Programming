n,m,k = map(int, input().split())
t = []
f = []
b = []
for i in range(k):
    l = list(map(int, input().split()))
    b.append(list(l[:2]))
    t.append(l[2])
    f.append(l[3])
print(b)
print(t)
print(f)
