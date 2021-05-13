n, k = map(int, input().split())
l = list(map(int, input().split()))

count=0
l.sort()
count1=0
i=0
j=0
while i<n and j<n:
	count1+=1
	if l[j]-l[i]>=k:	
		count+=n-j
		i+=1
	else:
		j+=1
print(count)
            
            

            
        