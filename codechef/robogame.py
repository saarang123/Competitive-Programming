def game(s):
    arr = []
    n = len(s)
    for i in range(n):
        if s[i] != ".":
            left = i - int(s[i])
            if left < 0:
                left = 0
            right = i + int(s[i])
            if right > n - 1:
                right = n - 1
            arr.append((i, left, right))
    ans = "safe"
    for i in range(len(arr)-1):
        if len(arr) == 1:
            break
        if arr[i][2] >= arr[i+1][1]:
            ans = "unsafe"
            break
    print(ans)
            
    
    
t = int(input())
for i in range(t):
    l = (input())
    game(l)
    