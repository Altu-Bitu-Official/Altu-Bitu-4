L = [list(map(int, input().split())) for _ in range(19)]

dx = [0, 1, 1, -1]
dy = [1, 0, 1, 1]

for x in range(19):
    for y in range(19):
        if L[x][y] != 0:
            # 시작 바둑돌 선택
            color = L[x][y]
            # 4가지 탐색 방향 중 1개 선택
            for i in range(4):
                # cnt를 1로 초기화
                cnt = 1
                # 탐색할 x, y 선택
                temp_x = x + dx[i]
                temp_y = y + dy[i]

                while 0 <= temp_x < 19 and 0 <= temp_y < 19 and L[temp_x][temp_y] == color:
                    cnt += 1
                    # 단방향 탐색
                    temp_x += dx[i]
                    temp_y += dy[i]
                if cnt == 5:
                    print(color)
                    print(x + 1, y + 1)
                    exit()

print(0)
