alpha = "abcdefghijklmnopqrstuvwxyz"
ok = []
for i in range(26):
    ok.append(0)
fib = [0, 1]
for i in range(30):
    fib.append(fib[-1] + fib[-2])

for i in range(26):
    ok[i] = (i + fib[i]) % 26
print(ok)
s = "apollomission"
ans = ""
for i in range(len(s)):
    cnt = ord(s[i]) - ord('a')
    ans += alpha[ok[cnt]]

print(ans)