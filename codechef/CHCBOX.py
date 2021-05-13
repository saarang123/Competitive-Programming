for t in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    m = max(l)
    pos = []
    for i in range(n):
        if l[i]==m:
               pos.append(i)
    diff = pos[len(pos)-1]-pos[0]
    if(diff>=n/2):
        print(0)
    else:
        ans = 0
        a = pos[-1]
        b = pos[0]
        for k in range(n):
            p1 = (a+k)%n
            p2 = (b+k)%n
            if(p1>(n/2)-1 and p2>(n/2)-1):
                ans+=1
        print(ans)
