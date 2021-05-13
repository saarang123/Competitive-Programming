t = int(input())
for i in range(t):
    n, a, b = map(int, input().split())
    s = list(map(int, input().split()))
    count_a = 0
    count_b = 0
    for p in range(n):
        if s[p]%a == 0:
            count_a += 1
        elif s[p]%b == 0:
            count_b += 1
    if count_a > count_b:
        print("BOB")
    elif count_b > count_a:
        print("ALICE")
    else:
        print("ALICE")

