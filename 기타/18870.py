import sys

N = int(sys.stdin.readline())
inp = list(map(int, sys.stdin.readline().split())) # 압축 전 숫자 리스트
inp_set = sorted(set(inp)) # 중복 제거 후 정렬
dic = {inp_set[i]:i for i in range(len(inp_set))} # 압축 전-압축 후 dictionary

# 순회하며 압축 후 숫자를 출력
for l in inp:
    print(dic[l], end=" ")