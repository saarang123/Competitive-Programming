n, m = map(int, input().split())
if(n - m > m-1):
    ans = m+1
else:
    ans = m-1
if(n==1):
    print(1)
else:
    print(ans)