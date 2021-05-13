def win(p, q):
    if (p[0] <= q[0] and p[1] > q[1]) or (p[0] < q[0] and p[1] >= q[1]):
        return p
    elif (p[0] >= q[0] and p[1] < q[1]) or (p[0] > q[0] and p[1] <= q[1]):
        return q
    else:
        return False
    
def mergesort(arr, s): 
    if len(arr) > 1: 
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:] 
        sL = s[:mid]
        sR = s[mid:]
        mergesort(L, sL)
        mergesort(R, sR) 
        i = j = k = 0
        while i < len(L) and j < len(R): 
            if win(L[i], R[j]) == L[i]: 
                arr[k] = R[j] 
                s[k] += 2
                i += 1
            elif win(L[i], R[j]) == R[j]: 
                arr[k] = L[i]
                s[k + mid] += 2
                j += 1
            else:
                s[k] += 1
                s[mid + k] += 1
                j += 1
            k += 1   
        while i < len(L): 
            arr[k] = L[i] 
            s[k] += 1
            i+=1
            k+=1
        while j < len(R): 
            arr[k] = R[j] 
            s[mid + k] += 1
            j+=1
            k+=1
        
def printlist(arr): 
    for i in range(len(arr)):         
        print(arr[i],end=" ") 
    print()           
    
t = int(input())
for i in range(t):
    n = int(input())
    arr = []
    for g in range(n):
        j = tuple(map(int, input().split()))
        arr.append(j)
    s = [0]*n
    mergesort(arr, s)
    printlist(s)
    

"""
for p in range(n):
        for q in range(p+1, n):
            if win(r[p], r[q]) == r[p]:
                s[p] += 2
            elif win(r[p], r[q]) == r[q]:
                s[q] += 2
            else:
                s[p] += 1
                s[q] += 1
"""