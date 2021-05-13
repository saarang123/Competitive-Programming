def good(x, z):
    global g
    g = []
    for i in range(len(x)):
        for j in range(len(z)-1, -1, -1):
            if x[i]<z[j]:
                if (z[j] - x[i] + 1)%3==0:
                    g.append((x[i],z[j]))
            else:
                break
        
def importance(s, g):
    global imp
    imp = 0
    for i in range(len(g)):
        if (s[1]<=g[i][1] and s[1]>=g[i][0]) or (s[0]>=g[i][0] and s[0]<=g[i][1]):
                imp+=1
  
t = int(input())
for i in range(t):
    n,k = map(int, input().split())
    s = list(map(str, input().split()))
    x, z, y = [], [], []
    for i in range(n):
        if s[i]=="X":
            x.append(i)
        elif s[i]=="Z":
            z.append(i)
        elif s[i]=="Y":
            y.append(i)
    good(x, z)
    if k==1:
        if len(y)>0:
            print(0)
        else:
            if len(g)>0:
                print(1)
    else:
        ans = []
        i = 0
        while (i+k)<n:
                s1 = (i, (i + k - 1))
                s2 = s[i:(i + k)]
                importance(s1, g)
                ans.append(imp)
                i+=1
        print(min(ans))