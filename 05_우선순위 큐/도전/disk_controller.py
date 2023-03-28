"""
    하드디스크는 한 번에 하나의 작업만 수행할 수 있음
    [작업이 요청되는 시점, 작업의 소요시간]을 담은 2차원 배열 jobs가 매개변수로
    작업의 요청부터 종료까지 걸린 시간의 평균을 가장 줄이는 방법으로 처리하면 평균이 얼마가 되는지 return 하도록 solution 함수를 작성
"""
import heapq
def solution(jobs):
    ans, p, i = 0,0,0
    time_start = -1
    heap = []

    while i < len(jobs):
        for j in jobs:
            if time_start < j[0] <= p:
                heapq.heappush(heap, [j[1],j[0]])
        if len(heap) > 0:
            current = heapq.heappop(heap)
            time_start = p
            p += current[0]
            ans += (p - current[1])
            i += 1
        else:
            p += 1
    return int(ans/len(jobs))