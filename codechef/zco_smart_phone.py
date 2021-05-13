n = int(input())
l = []
for i in range(n):
    l.append(int(input()))
l.sort()

ans = []
for i in range(n):
    ans.append((n-i)*l[i])
print(max(ans))