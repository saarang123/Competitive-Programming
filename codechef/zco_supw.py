n = int(input())
s = list(map(int, input().split()))
ans = 0
l = []
a = []
def supw(s,n,ans, l,a):
    global ans2
    ans2 = ans
    if s in l:
        ans2 = a[l.index(s)]
    else:
        if n>=3:
            s1 = s[1:]
            s2 = s[2:]
            s3 = s[3:]
            n1 = len(s1)
            n2 = len(s2)
            n3 = len(s3)
            ans2 += min((s[0] + supw(s1,n1,ans,l,a)), (s[1] + supw(s2,n2, ans,l,a)),(s[2] + supw(s3,n3,ans,l,a)))
    l.append(s), a.append(ans2)
    return ans2

supw(s,n,ans,l,a)
print(ans2)
