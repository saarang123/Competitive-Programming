from collections import Counter

n = int(input())
arr = []
for i in range(n):
    s = map(str,input().split())
    arr.append("".join(s))

c = Counter(arr)
keys = list(c.keys())
ans = []

for item in keys:
    x = c[item]
    if x == item.count("T"):
        ans.append(x)

if len(ans) != 0:
    print(max(ans))
else:
    print(0)