n = int(raw_input())
ans = []
for i in range(n):
    ans.append(raw_input().split())

ans.sort(key = lambda x: int(x[2]))

def out(x):
    print x[0] , x[1]

out(ans[n-1])
out(ans[0])
