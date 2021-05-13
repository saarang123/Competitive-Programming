def maxSubArraySum(a,size): 
    max_so_far = -1000000000 - 1
    max_ending_here = 0
    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here
        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far

def smallestSumSubarr(arr, n): 
    min_ending_here = 1000000000+1
    min_so_far = 1000000000+1
    for i in range(n): 
        if (min_ending_here > 0): 
            min_ending_here = arr[i] 
        else: 
            min_ending_here += arr[i] 
        min_so_far = min(min_so_far, min_ending_here) 
    return min_so_far


t = int(input())
for _ in range(t):
    n = int(input())
    d = list(map(int, input().split()))
    maximum = 0
    for p in range(1, n-1):
        beg = d[:p]
        end = d[p:]
        temp1 = abs(maxSubArraySum(beg, p) - smallestSumSubarr(end, n-p))
        temp2 = abs(maxSubArraySum(end, n-p) - smallestSumSubarr(beg, p))
        maximum = max(maximum, max(temp2, temp1))
    print(maximum)        