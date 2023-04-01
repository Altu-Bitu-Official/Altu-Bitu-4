import sys

N = int(sys.stdin.readline())
# 계수 정렬
l = [0 for i in range(10000)]

for _ in range(N):
    l[int(sys.stdin.readline()) - 1] += 1
for i in range(len(l)):
    for _ in range(l[i]):
        print(i + 1)
