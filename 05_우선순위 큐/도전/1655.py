"""
    "가운데를 말해요" 게임
    동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다.
    백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
    동생이 말해야 하는 수를 구하는 프로그램을 작성
"""

import heapq
import sys
n = int(input()) # 백준이가 외치는 정수의 개수

Heap1 = []
Heap2 = []

for i in range(n):
    num = int(sys.stdin.readline())

    if len(Heap1) == len(Heap2):
        heapq.heappush(Heap1, -num)
    else:
        heapq.heappush(Heap2, num)

    if Heap2 and Heap2[0] < -Heap1[0]:
        value1 = heapq.heappop(Heap1)
        value2 = heapq.heappop(Heap2)

        heapq.heappush(Heap1, -value2)
        heapq.heappush(Heap2, -value1)

    print(-Heap1[0])
