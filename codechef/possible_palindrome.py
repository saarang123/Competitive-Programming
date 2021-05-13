#Program to check if input can be made into palindrome or not
from collections import Counter
p = input()
l = []
for i in range(len(p)):
     l.append(p[i])   
d = Counter(l)
k = d.keys()
count = 0
for key in k:
    if d[key] % 2 != 0:
        count += 1
if count <= 1:
    print(1)
else:
    print(0)