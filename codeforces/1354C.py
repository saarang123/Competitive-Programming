from math import *

p = pi

def con(x):
    return x*p/180;

for _ in range(int(input())):
    n = int(input())
    angle = (180 - (360/(2*n)))/2
    #print(angle)
    angle = con(angle)
    #print(angle)
    ans = (tan(angle))
    print(round(ans, 15))
    
