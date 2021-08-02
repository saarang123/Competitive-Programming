from math import *

def check(x):
    n = x
    sm = 0
    while x > 0:
        sm += x % 10
        x //= 10
    return gcd(n, sm) > 1

for _ in range(int(input())):
    n = int(input())
    while True:
        if check(n):
            ans = n
            break
        n += 1
    print(ans)
