N = int(input())
l = []

for _ in range(N):
    x, y= map(int, input().split())
    l.append((y, x))

for t in sorted(l):
    print(t[1],t[0])
