n,m = map(int, input().split())
s = [input() for _ in range(n)]
l = [0]*n
ans = ""
ans2 = ""
for i in range(n):
    for j in range(i+1,n):
        if(s[i][::-1]==s[j]):
            ans+=s[i]
            ans2+=s[j]
            l[i] = 1
            l[j] = 1
j = ""
for i in range(n):
    if(l[i]==0):
        if(s[i]==s[i][::-1]):
            j = s[i]
sol = ans + j + ans[::-1]
print(len(sol))
print(sol)

