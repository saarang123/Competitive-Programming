fi = open("1.in", 'r')
fo = open("badmilk.out", 'w')
n, m, d, s = map(int, fi.readline().split())
print(n,m,d,s)
milk = [[]]*(m+1)
print(milk)
for i in range(d):
    p, mi, t = map(int, fi.readline().split())
    print(mi)
    milk[mi].append((p,t))
print(milk) 