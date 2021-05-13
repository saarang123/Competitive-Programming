import math
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    s = sum(l)
    ans = math.ceil(s/n)
    print(ans)
    