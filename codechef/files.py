"""class LN:
    def __init__(self,value,next=None):
        self.value = value
        self.next  = next

    def list_to_ll(l):
        if l == []:
           return None
        front = rear = LN(l[0])
        for v in l[1:]:
            rear.next = LN(v)
            rear = rear.next
        return front"""
        
a = [2,3,23,15,13,1,4]
n = len(a)
l = [0]*n
l[n-1] = 1
for i in range(n-2):
    if a[i] < a[i+1]:   
        l[i] = 1 + l[i-1]
    else:
        l[i] = 1
print(l)