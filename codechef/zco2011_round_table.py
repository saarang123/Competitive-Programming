n = int(input())
l = list(map(int, input().split()))

def val(a):
    mi = [0]*n
    mi[0] = a[0]
    mi[1] = a[1]
    for i in range(2,n):
        mi[i] = a[i] + min(mi[i-1], mi[i-2])
    return(mi[n-1])
i = val(l)
l.reverse()
j = val(l)
print(min(i, j))