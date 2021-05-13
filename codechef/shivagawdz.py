def maxsum(a,size): 
       
    max_so_far = -10**10 - 1
    max_ending_here = 0
       
    for i in range(0, size): 
        max_ending_here = (max_ending_here + a[i]) / 1+i
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
  
        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far 
l = [5, 4, 3, 2, 1]
print(maxsum(l, len(l)))