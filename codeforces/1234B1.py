n, k = map(int, input().split())
l = list(map(int, input().split()))
q = []

    
for i in range(n):
    if l[i] not in q:
        if(len(q)==k):
            del q[-1]
        q.insert(0, l[i])
print(len(q))
print(*q)