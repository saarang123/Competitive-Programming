def my_max(s):
    global maximum
    maximum = s[0]
    for i in range(len(s)):
        if s[i][1] > maximum[1]:
            maximum = s[i]
    return maximum

n = int(input())
l = list(map(int, input().split())) 
i = 0
nest = []
j = 0
count = 0
mex = []
for k in range(n):
    if l[k] == 1:
        i += 1
        j += 1
        count += 1
        nest.append((k + 1, i))
    else:
        i = 0
        count+=1
        j -= 1
        if j == 0:
            mex.append((k - count + 2,count))
            count = 0
            
ans = ''
(my_max(nest))
ans+= str(maximum[1]) +' ' + str(maximum[0]) + ' '
my_max(mex)
ans+= str(maximum[1]) + ' ' + str(maximum[0])

print(ans)