import math

N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())
n = 0
for i in range(N):
    n += 1
    A[i] -= B
    if A[i] > 0:
        n += math.ceil(A[i] / C)
print(n)
