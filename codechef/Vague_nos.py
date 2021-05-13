def sumDigits(no): 
    return 0 if no == 0 else int(no%10) + sumDigits(int(no/10)) 

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    ans = 0
    temp = min(n, m + 10 - m%10)
    while(True):
        if(temp-sumDigits(temp)>=m):
            ans = abs(n-temp+1)
            break
        else:
            temp+=10
            if(temp>n):
                break
    print(ans)
        
