t=int(input())
for _ in range(t):
    p1,p2,k=list(map(int,input().split()))
    s=p1+p2
    res=s//k
    if res%2==0:
        print ("CHEF")
    else:
        print ("COOK")