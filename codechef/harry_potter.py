def shuffle(l,n):
    count = 0
    for i in range(len(l)-1):
        if l[i] > l[i+1]:
            count+=1
    if count<=1:
        print("YES")
    else:
        print("NO")
        
t = int(input())                                                                					
for q in range(0,t):  
    n = int(input())
    list = []
    obj = (input())                                                              				
    for no in obj.split():
        list.append(int(no))
    shuffle(list,n)
        
    