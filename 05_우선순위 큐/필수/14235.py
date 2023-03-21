"""
    세계 곳곳에 거점들을 세워 그 곳을 방문하며 선물을 충전해 나갈 것
    한 아이들을 만날 때마다 자신이 들고있는 가장 가치가 큰 선물 하나를 선물
    아이들이 준 선물들의 가치들을 출력하시오. 만약 아이들에게 줄 선물이 없다면 -1을 출력하시오.
"""

import heapq

n = int(input())
queue = []

for i in range(n):
    a = list(map(int, input().split())) # 거점에서 선물을 충전
    if a[0] == 0:
        if len(queue) == 0:  # 선물이 없으면
            print(-1)
        else:  # 선물이 있으면
            tmp = -heapq.heappop(queue)
            print(tmp)
    else:
        for j in range(a[0]):
            heapq.heappush(queue, -a[j + 1])
