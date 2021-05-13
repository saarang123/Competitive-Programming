n, m = map(int, input().split())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
mini = l2.index(min(l2))
maxi = l1.index(max(l1))

for i in range(0,n):
    print(i,mini)
for i in range(0,m):
    if(i!=mini):
        print(maxi,i)