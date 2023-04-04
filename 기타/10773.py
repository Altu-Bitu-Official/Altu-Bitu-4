import sys
K = int(sys.stdin.readline())
stack = []
ans = 0
for _ in range(K):
    n = int(sys.stdin.readline())
    if n == 0:
        ans -= stack.pop()
    else:
        ans += n
        stack.append(n)
print(ans)