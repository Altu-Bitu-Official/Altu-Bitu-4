from collections import deque
N, M = map(int, input().split())
L = [[] for _ in range(N)]
maxCnt = 1
maxNum = []

for _ in range(M):
    a, b = map(int, input().split())
    L[b - 1].append(a - 1)

for i in range(N):
    cnt = 0
    queue = deque([i])
    visit = [False for _ in range(N)] # 방문 표시
    visit[i] = True

    while queue:
        for m in L[queue.popleft()]:
            if not visit[m]:
                cnt += 1
                visit[m] = True
                queue.append(m)

    if maxCnt < cnt:
        maxCnt = cnt
        maxNum.clear()
        maxNum.append(i + 1)
    elif maxCnt == cnt:
        maxNum.append(i + 1)

print(* maxNum)


