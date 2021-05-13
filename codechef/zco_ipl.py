n = int(input())
s = list(map(int,input().split()))
var = [0]*n
var[0] = s[0]
var[1] = s[1]
var[2] = s[2]
for i in range(3,n):
    var[i] = s[i] + min(var[i-1], var[i-2], var[i-3])
print(sum(s) - min(var[n-1], var[n-2], var[n-3]))
