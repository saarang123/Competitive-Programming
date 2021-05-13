n = int(input())
s = list(map(int, input().split()))
s.sort()
s.reverse()
ans = 0
j = 0
for i in range(0, n, ++2):
    ans += (n - i - 1)*(s[j] - s[-(j+1)])
    j += 1
    
print(ans)