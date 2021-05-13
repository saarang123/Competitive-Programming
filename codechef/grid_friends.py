t = int(input())
for i in range(t):
    f, s = map(int, input().split())
    a = list(map(int, input().split()))
    p1 = a[0]
    p2 = a[1]
    ans = []
    c = 1
    for i in range(f-1):
        a = list(map(int, input().split()))
        if (a[0] == p1 and a[1] != p2) or (a[1] == p2 and a[0] != p1):
            c += 1
        elif (a[0] == p1 and a[1] == p2):
            ans.append(1)
            c = 0
            p1 = a[0]
            p2 = a[1]
        else:
            ans.append(c)
            c = 0
            p1 = a[0]
            p2 = a[1]
    if c==f:
        ans.append(f)
    print("Case #" + str(i) + ": " + str(max(ans)))
          
            
    
    
        
