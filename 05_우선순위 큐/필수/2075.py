"""
    수가 N 제곱개.
    모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것
"""
import heapq

n = int(input())
queue = []
for i in range(n):
    num_list = list(map(int, input().split()))
    # 첫번째 입력
    if not queue:
        for num in num_list:
            heapq.heappush(queue, num)
    # queue에 값이 있는 경우
    else:
        for num in num_list:
            # queue 최솟값보다 현재 숫자가 클 경우
            if queue[0] < num:
                heapq.heappush(queue, num)  # 현재 숫자를 push
                heapq.heappop(queue)  # 기존값 pop
print(queue[0])
