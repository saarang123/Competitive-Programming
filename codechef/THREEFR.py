t = int(input())
for i in range(t):
    k = input()
    l= []
    for n in k.split():
        l.append(int(n))
    sum = l[0]+l[1]+l[2]
    for no in l:
        if sum-(2*no)==0:
            ans = "yes"
            break
        else:
            ans = "no"
    print(ans)  