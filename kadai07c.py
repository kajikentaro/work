import math
k = 0
def method(c):
    if len(c) > 1:
        a = method(c[:math.floor(len(c)/2)])
        b = method(c[math.floor(len(c)/2):])
    else :
        return c
    
    c = []
    ca = cb = 0
    global k
    while ca < len(a) and cb < len(b):
        if a[ca] < b[cb]:
            c.append(a[ca])
            ca = ca + 1
        else:
            k += len(a) - ca
            c.append(b[cb])
            cb = cb + 1
    for  i in range(ca,len(a),1):
        c.append(a[i])
    for  i in range(cb,len(b),1):
        c.append(b[i])
    return c
a = [int(i) for i in input().split()]
method(a)
print(k)