def restaurant(n, m, k, l, a):
    time = []
    if n==1:
        ppl = min((m - int(a[0]/l) + 1), (m - int(k/l) + 1))
        print(ppl)
        present = ((ppl-1)*l) + (l-(a[0]%l)) 
        print(time)
        time.append(present)
    else:
        for t in range(len(a)):
            ppl = (m - int(a[t]/l) + t + 1)
            print(ppl)
            present = ((ppl-1)*l) + (l-(a[t]%l)) 
            time.append(present)
            print(time)
    print (min(time))
        
tt = int(input())
for _ in range(tt):
    n, m, k, l = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    restaurant(n, m, k, l, a)