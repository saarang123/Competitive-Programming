t = int(input())
for i in range(t):
    k = int(input())
    sum = 0
    for i in range(1,k+1,2):
        if i!=k:
            j=i
            j=k-i+1
            sum+=j*j
        else:
            sum+=1
    print(sum)