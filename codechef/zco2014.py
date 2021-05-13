l1=input()
n,h = map(int, l1.split())
l2 = input()
i = list(map(int, l2.split()))
l3 = input()
c = list(map(int, l3.split()))
b = len(i)
pointer = 0
box = 0
for g in range(len(c)):
    if c[g]==1 and pointer!=0:
        pointer-=1
    elif c[g]==2 and pointer!=b-1:
        pointer+=1
    elif c[g]==3 and i[pointer]>0 and box==0:
        i[pointer]-=1
        box = 1
    elif c[g]==4 and i[pointer]<h and box==1:
        i[pointer]+=1
        box = 0

ans=''
for j in range(b):
    ans+=str(i[j])+' '
print (ans)