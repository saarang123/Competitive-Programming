n = int(input())
bx, by = map(int, input().split())
ax, ay = map(int, input().split())
cx, cy = map(int, input().split())
ans = "NO"
if(ax<bx and cx<bx):
    if(ay<by and cy<by):
        ans = "YES"
    elif(ay>by and cy>by):
        ans = "YES"
elif(ax>bx and cx>bx):
    if(ay<by and cy<by):
        ans = "YES"
    elif(ay>by and cy>by):
        ans = "YES"
print(ans)