n = int(input())
l = input()
a = list(map(int, l.split()))
count = 0
bcount = 0
for i in range(n):
    if a[i]%2 == 0:
        count+=1
    else:
        bcount+=1
if count>bcount:
    print("READY FOR WAR")
else:
    print("NOT READY")  