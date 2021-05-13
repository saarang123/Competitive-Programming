def maxsum(a,n): 
    global max_now   
    max_now = -2
    max_here = 0
       
    for i in range(0, n): 
        max_here = max_here + int(a[i])
        if (max_now < max_here): 
            max_now = max_here 
  
        if max_here < 0: 
            max_here = 0   
    return max_now 

t=int(input())
for i in range(t):
    n = int(input())
    s = list(input())
    for g in range(n):
        if s[g] == "0":
            s[g] = "1"
        else:
            s[g] = "-1"
    maxsum(s,n)
    print(max_now)
    