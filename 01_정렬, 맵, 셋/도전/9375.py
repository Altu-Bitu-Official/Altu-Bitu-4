import sys

T = int(sys.stdin.readline())
ans = ""

for _ in range(T):
    N = int(sys.stdin.readline())
    clothes_list = {}
    cnt = 1
    for i in range(N):
        _, type = sys.stdin.readline().split()
        #  의상 종류별 개수를 저장
        if type in clothes_list.keys():
            clothes_list[type] = clothes_list[type] + 1
        else:
            clothes_list[type] = 2

    for c in clothes_list.values():
        cnt *= c
    ans += str(cnt - 1) + '\n' # 맨몸인 상황을 제외

print(ans)