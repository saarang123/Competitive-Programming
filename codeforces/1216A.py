n = int(input())
s = input()
c = 0
ans = ''
for i in range(0, n-1, 2):
    ans+=s[i]
    if(s[i]==s[i+1]):
        c+=1
        if(s[i]=='a'):
            ans+='b'
        else:
            ans+='a'
    else:
        ans+=s[i+1]
print(c)
print(ans)  