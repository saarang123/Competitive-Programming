n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
count = 0
l=0
h=n-1
while l<h:
    if arr[l]+arr[h]<k:
        count  =count + h - l
        l += 1
    else:
        h -= 1

print(count)