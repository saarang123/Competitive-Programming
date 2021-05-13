t = int(input())
for _ in range(t):
    n = input()
    if(len(n)==1):
        print(0)
    elif(n[1]=='0'):
        if(len(n)==2):
            print(0)
        else:
            print(int(n[2:]))
    else:
        if(int(n[0]) < int(n[1])):
            ind = 0
            for i in range(0, len(n)):
                if(int(n[i])>int(n[i-1])):
                    ind = i
                    break
            print(int(n[0:ind] + n[ind+1:]))
        else:
            n = "0"+ n
            ind = 1
            for i in range(1, len(n)):
                if(int(n[i])>int(n[i-1])):
                    ind = i
                    break
            print(int(n[1:ind] + n[ind+1:]))
