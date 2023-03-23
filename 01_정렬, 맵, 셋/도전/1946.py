"""
1차 서류심사와 2차 면접시험
다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다
어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.
첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)
각 테스트 케이스의 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)
둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다.
두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정
"""
import sys
T = int(sys.stdin.readline())
answer = ""

for _ in range(T):
    N = int(sys.stdin.readline())
    person = [0 for i in range(N)]
    cnt = 1

    for i in range(N):
        s1, s2 = sys.stdin.readline().split()
        person[int(s1)-1] = int(s2)

    highest_rank = person[0]
    for i in range(1, len(person)):
        if highest_rank > person[i]:
            cnt += 1
            highest_rank = person[i]

    answer += str(cnt)+'\n'

print(answer)
