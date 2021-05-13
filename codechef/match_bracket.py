n = int(input())
s = list(map(int, input().split()))
nd = 0                                   #nesting depth
mnd = 0                                  #maximum nesting depth
mnp = 0                                  #maximum nesting depth position
ms = 0                                   #middle symbols
mms = 0                                  #maximum middle symbols
pp = -1                                  #previous position for maximum symbol
cp = -1                                  #current position for maximum symbol
mmp = 0                                  #middle symbol starting position
for i in range(n):
    if s[i]==1:
        nd += 1
        if nd>mnd:
            mnd = nd
            mnp = i+1
    else:
        nd -= 1
    if nd==0:
        pp = cp
        cp = i
        ms = cp - pp
        if ms>mms:
            mms = ms
            mmp = pp + 2
print (mnd, mnp, mms, mmp)