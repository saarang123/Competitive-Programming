T = int(input())
for _ in range(T):
    N = int(input())
    ls1 = list(map(int, input().split()))
    ls2 = list(map(int, input().split()))
    front = 0
    back = 0
    i = N-1
    j = 0
    while i>=0:
        if ls2[i]>=ls1[j]:
            back+=1
        if ls2[i]>=ls1[i]:
            front+=1
        i-=1
        j+=1
    if front==N and back==N:
        print('both')
    elif front==N:
        print('front')
    elif back==N:
        print('back')
    else: print('none')
