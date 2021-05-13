def pal(arr,x,y):
    while(x<y):
        if(arr[x]!=arr[y]):
            return False
        x+=1
        y-=1
    return True
n=int(input())
arr=[int(x) for x in input().split()]
var=[n for i in range(n)]
var[n-1]=1
for i in range(n-2,-1,-1):
    for j in range(n-1,i-1,-1):
        if(pal(arr,i,j)):
            if(j==n-1):
                var[i]=1
            else:
                var[i]=min(var[i],1+var[j+1])
print (var[0])