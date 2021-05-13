a = input()
b = input()
diff = (int(b[:2]) - int(a[:2]))*60 + int(b[3:]) - int(a[3:])
ans = int(a[:2])*60 + int(a[3:]) + diff/2
print(ans)
soln = str(int(ans/60)) + ":" + str(int(ans%60))