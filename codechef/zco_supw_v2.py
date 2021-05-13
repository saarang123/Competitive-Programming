n = int(input())
s = list(map(int, input().split()))
ans = 0
def l_min(s):
    global m,j
    m = s[0]
    j = 0
    for i in range(1,3):
        if s[i]<=m:
            m = s[i]
            j = i
def supw(s,n, ans):
    global ans2
    ans2 = ans
    if n>=3:
        l_min(s)
        ans+=m
        del s[0:(j+1)]
        n = len(s)
        s1 = s[1:]
        s2 = s[2:]
        s3 = s[3:]
        n1= len(s1)
        n2 = len(s2)
        n3 = len(s3)
        ans+=supw(s,n,ans)
    return ans2
if n<=3:
    ans2 = min(s)
else:
    s1 = s[1:]
    s2 = s[2:]
    s3 = s[3:]
    n1= len(s1)
    n2 = len(s2)
    n3 = len(s3)
    ans2 = min((s[0] + supw(s1,n1,ans)), (s[1] + supw(s2,n2, ans)),(s[2] + supw(s3,n3,ans)))   
print(ans2)
