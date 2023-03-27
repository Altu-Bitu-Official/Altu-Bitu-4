import sys
N = int(sys.stdin.readline()) # 정렬할 수의 개수
l = [0 for _ in range(N)] # 정렬할 수 리스트
_sum = 0 # 수의 합
_max = -4000 # 수의 최댓값
_min = 4000 # 수의 최솟값
_count = [0 for _ in range(8001)] # _count[0]: -4000 ~ _count[8000]: 4000 개수 리스트
count_max = 0 # 최대 개수
mode = [] # 최빈값 리스트
ans = ""

for i in range(N):
    l[i] = int(sys.stdin.readline())
    _sum += l[i] # 수의 합
    if l[i] > _max: # 수의 최댓값
        _max = l[i]
    if l[i] < _min: # 수의 최솟값
        _min = l[i]
    _count[4000+l[i]] += 1 # 개수 저장
    if _count[4000+l[i]] > count_max:
        count_max = _count[4000+l[i]] # 최대 개수
        mode.clear()
        mode.append(l[i]) # 최빈값에 추가
    elif _count[4000+l[i]] == count_max:
        mode.append(l[i]) # 최빈값에 추가

ans += str(round(_sum/N))+"\n"
ans += str(sorted(l)[N//2])+"\n"
# 최빈값 출력
if len(mode) == 1:
    ans += str(sorted(mode)[0])+"\n"
else:
    ans += str(sorted(mode)[1])+"\n"
ans += str(_max - _min)

print(ans)