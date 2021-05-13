n = int(input())
k = int(input())
a = int(input())
b = int(input())

if(k == 1):
    print((n - 1) * a)
    quit()
ans = 0
while(n > 1):
    if(n < k):
        ans += (n - 1) * a
        n = 1
        continue;
    ans += min((n % k) * a + b, (n - ((n - (n % k))//k)) * a)
    n -= n % k
    n //= k
    #print(ans, n)
print(int(ans))
    
