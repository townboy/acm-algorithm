import sys

sys.stdin = open('in', 'r')
sys.stdout = open('out', 'w')

n = int(raw_input())

num = [0 for i in range(1000000)]

for i in range(n):
    a = map(int ,raw_input().split())
    if 1 == len(a):
        for f in range(999999, 0, -1):
            if 0 != num[f]:
                print f
                break
    elif 1 == a[1]:
        num[a[1]] += 1
    else:
        num[a[1]] -= 1

