import math
import sys
n = int(sys.stdin.readline())
v = list(map(int, sys.stdin.readline().split()))[::-1] # 행성 순서를 reverse

v_min = v[0]
for i in range(1, n):
    if v_min == v[i]:
        continue
    elif v_min < v[i]: # 속도를 떨어뜨릴 수 있으므로
        v_min = v[i]
    else: # v[i] * (m-1) < v_min <= v[i] * m 인 m 찾기
        m = math.ceil(v_min / v[i])
        v_min = v[i] * m
print(v_min)

