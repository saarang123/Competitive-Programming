n = int(input())
a = list(map(int, input().split()))
b = sorted(a, reverse = True)
ans = 0
for i in range(n):
    ans += b[i]*i + 1
print(ans)

l = []
for i in range(n): 
    min_idx = i 
    for j in range(i+1, len(a)): 
        if a[min_idx] < a[j]: 
            min_idx = j
    a[i], a[min_idx] = a[min_idx], a[i]
    l.append(i)
print(l)
"""
new_ar = list(zip(a,[i for i in range(len(a))]))
new_ar.sort(reverse = True)
print(new_ar)
s = [str(new_ar[i][1]+1)+ " " for i in range(n)]
print(*s)"""