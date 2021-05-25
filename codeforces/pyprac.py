from math import *
e = 2.718281828

for n in range(1, 7 + 1):

    x = pow(e, (-1 * (n**2)))
    f_function = (sqrt(1 + x) - 1)/x

    print(n, " --> ", f_function)