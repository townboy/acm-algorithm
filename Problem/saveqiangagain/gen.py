import sys
import random
sys.stdout = open('in', 'w');

map = []

def randtwo():
    return random.randint(0, 14), random.randint(0, 14)

def randst():
    a, b = randtwo()
    while True:
        c, d = randtwo()
        if a != c or b != d:
            break
    map[a][b] = 2;
    map[c][d] = 3;

str = '.#ST'

def printmap():
    for i in range(15):
        line = ''
        for f in range(15):
            line = line + str[map[i][f]]
        print line

for case in range(100):
    print 15, 15
    map = []
    for i in range(15):
        map.append([]);
        for f in range(15):
            map[i].append(0)
    randst()

    for i in range(15):
        for f in range(15): 
            if 0 == map[i][f]:
                tt = random.randint(0, 19)
                if tt < 5:
                    map[i][f] = 1
                else:
                    map[i][f] = 0
    printmap()
