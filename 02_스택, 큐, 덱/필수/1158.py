from collections import deque
N, K = map(int, input().split())
ans = '<'
deq = deque(p for p in range(1, N+1)) # 덱에 1~N 저장

while True:
    if len(deq) == 0:
        print(ans[:-2] + '>')
        break
    for i in range(K):
        item = deq.popleft()
        if i != K-1: # K번째 사람이 아니면 다시 enqueue
            deq.append(item)
        else: # K번째 사람이면 ans에 추가
            ans += str(item) + ', '

