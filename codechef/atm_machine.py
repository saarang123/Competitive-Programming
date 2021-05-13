"""t = int(input())
for i in range(t):
    l = input()
    n = int(l.split()[0])
    k = int(l.split()[1])
    l2 = input()
    a = list(map(int, l2.split()))
    ans = ''
    for m in a:
        if m<=k:
            k-=m
            ans+='1'
        else:
            ans+='0'
    print (ans)"""
from random import randint

s = ''
for i in range(10000):
    s+=str(randint(0,10)) + ' '
print(s)