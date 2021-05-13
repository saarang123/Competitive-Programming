t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.append(0)
    s = []
    i = 0
    if(a[0]>0):
        e=True
    else:
        e=False
    c = 1
    while(i<=n-1):
        if(e==True and a[i+1]<0):
            e=False
            c+=1
            i+=1
        elif(e==False and a[i+1]>0):
            e=True
            c+=1
            i+=1
        else:
            i+=1
            s.append(c)
            c=1
    ans = ""
    for el in s:
        for k in range(el, 0, -1):
            ans+=str(k)+" "
    print(ans)
