import sys
import random

sys.stdout = open('in', 'w')

print '1000000'
cnt = 0

ll = []

def funA():
    tt = random.randint(0,999999)
    ll.append(tt)
    print 1, tt

def funB():
    ll_len = len(ll)
    de = random.randint(0, ll_len - 1)
    print 2, ll[de]
    del ll[de]

last = None
for i in range(1000000):
    if 0 == len(ll):
        funA()
        last = 1
        continue

    if 0 == last:
        get = random.randint(0, 69)
    else:
        get = random.randint(0, 99)

    if get < 36:
        funA()
        last = 1
    elif get < 70:
        funB()
        last = 2
    else:
        last = 0
        print '0'
