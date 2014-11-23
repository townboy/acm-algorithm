import sys
import random
sys.stdout = open('data', 'w')

for i in range(1000):
    n = 100
    m = random.randint(30, 45)
    print n ,m
    for f in range(n):
        x = random.randint(0, 10000)
        y = random.randint(0, 10000)
        print x, y
