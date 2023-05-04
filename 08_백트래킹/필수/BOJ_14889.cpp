#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20; // 상수 N을 20으로 선언
const int INF = 1e9;  // 임시로 넣어두는 값

int n;
int min_power_gap = INF; // min_power_gap초기화
int s[MAX_N][MAX_N];     // 능력치 s 선언
bool is_start[MAX_N];    // 스타트팀 또는 링크팀 선언

int calcTeamPowerGap()
{                        // 팀의 능력치 차이를 계산하는 함수
    int start_power = 0; // 스타트팀 능력치 초기화
    int link_power = 0;  // 링크팀 능력치 초기화

    for (int i = 0; i < n - 1; i++)
    { // i :  n-2번 반복
        for (int j = i + 1; j < n; j++)
        {                                 // j : i+1부터 n-1까지 반복
            int ssum = s[i][j] + s[j][i]; // 능력치를 저장하는 변수 ssum선언

            // i와 j 모두 스타트 팀인 경우
            if (is_start[i] && is_start[j])
            {
                start_power += ssum; // 스타트팀능력치 증가
            }
            // i와 j 모두 링크 팀인 경우
            else if (!is_start[i] && !is_start[j])
            {
                link_power += ssum; // 링크팀 능력치 증가
            }
        }
    }

    return abs(start_power - link_power); // 링크팀과 스타트팀의 능력치 차이 반환
}

// 가장 빠른 번호와 뽑은 사람 수를 입력하여 minpowergap, is_start 배열 변경
void backtrack(int idx, int cnt)
{
    // 재귀 호출 종료 조건: n/2명을 다 뽑은 경우
    if (cnt == (n / 2))
    {
        int power_gap = calcTeamPowerGap();            // n/2명을 다 뽑은 경우 powergap을 저장
        min_power_gap = min(min_power_gap, power_gap); // powergap과 min_power_gap중 작은 값을 저장
        return;
    }

    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++)
    {
        is_start[i] = true;        // i번째 팀원을 스타트팀원으로
        backtrack(i + 1, cnt + 1); // 다음 번호부터 다시 스타트팀원 선정
        is_start[i] = false;       // i번째 팀원을 링크팀원으로
    }
}

int main()
{
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) // n번 반복
    {
        for (int j = 0; j < n; j++) // n 번 반복
        {
            cin >> s[i][j]; // s 사용자정의
        }
    }

    // 연산
    is_start[0] = true; // 0번이 있는 팀은 스타트팀으로 지정
    backtrack(1, 1);    // 1번부터 백트래킹 시작

    // 출력
    cout << min_power_gap << '\n'; // 가장 근소한 능력치를 출력

    return 0; // 종료
}