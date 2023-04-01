import sys

N = int(sys.stdin.readline())
s = []
ans = ""

for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    s.append((x, y))

for t in sorted(s):
    print(t[0], t[1])