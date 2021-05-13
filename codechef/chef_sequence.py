x=int(input())
for _ in range(x):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    c=0
    for i in l:
        if i is 1:
            c=c+1 
    if n-c<=k:
        print("YES")
    else:
        print("NO")