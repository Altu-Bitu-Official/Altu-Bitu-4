N = int(input())  # 퇴사까지 남은 일수
schedule = [list(map(int, input().split())) for i in range(N)] # [소요일수, 비용]

dp = [0 for i in range(N+1)] # dp[i] = i일까지의 최대 수익

# i번째까지 일했을 때 얻는 최대 수익
for i in range(N):
    for j in range(i+schedule[i][0], N+1):
        if dp[j] < dp[i] + schedule[i][1]: # i번째 날에 상담을 진행할 경우 수익이 더 높다면
            dp[j] = dp[i] + schedule[i][1]

print(dp[-1])


