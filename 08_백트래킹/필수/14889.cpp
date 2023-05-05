#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
const int INF = 1e9;

int n; // 사람 수
int min_power_gap = INF; // 최소 차이
int s[MAX_N][MAX_N];     // 능력치
bool is_start[MAX_N];    // 스타트팀인지 여부

int calcTeamPowerGap() { // 스타트와 링크의 능력치 차이 계산
    int start_power = 0; // 각각 0으로 초기화
    int link_power = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int ssum = s[i][j] + s[j][i]; // 양쪽 능력치를 더해준다
            
            // i와 j 모두 스타트 팀인 경우
            if (is_start[i] && is_start[j]) {
                start_power += ssum; // 스타트의 능력치 증가
            }
            // i와 j 모두 링크 팀인 경우
            else if (!is_start[i] && !is_start[j]) {
                link_power += ssum;  // 링크의 능력치 증가
            }
        }
    }

    return abs(start_power - link_power); // 차이이므로 절댓값으로 반환
}

/**
 * 스타트팀원을 한명씩 뽑는다.
 * 중복 탐색을 막기 위해 팀원의 번호가 오름차순이 되도록 뽑는다.
 * ex) [1, 2]와 [2, 1]은 같은 케이스 이므로 [1, 2]만 탐색
 *
 * idx: 남은 사람들 중 가장 빠른 번호
 * cnt: 현재까지 뽑은 사람 수
 */
void backtrack(int idx, int cnt) {
    // 재귀 호출 종료 조건: n/2명을 다 뽑은 경우
    if (cnt == (n / 2)) {                              // n/2명을 다 뽑으면
        int power_gap = calcTeamPowerGap();            // 능력치 차이 계산
        min_power_gap = min(min_power_gap, power_gap); // 최소 능력치 차이 계산
        return;
    }
    
    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++) { // idx번부터 탐색
        is_start[i] = true;         // 사용
        backtrack(i + 1, cnt + 1);  // 인덱스, 카운트 증가시켜 다음 사람 뽑기
        is_start[i] = false;        // 반납
    }
}

/**
 * 스타트: [1, 2], 링크: [0, 3]인 경우와
 * 스타트: [0, 3], 링크: [1, 2]인 경우는 같다.
 * 특정 사람이 있는 팀 / 없는 팀으로만 구별하면 된다.
 * 0번이 있는 팀과 없는 팀으로 구별하자. 그리고 0번이 있는 팀을 스타트팀이라고 부르자.
 * 스타트팀을 뽑는 모든 조합을 전부 시도해본다.
 */
int main() {
    // 입력
    cin >> n; // 사람 수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j]; // 능력치
        }
    }

    // 연산
    is_start[0] = true; // 스타트팀인지 여부, 0번 사람은 스타트 팀
    backtrack(1, 1);    // 순서대로 뽑기 위해 인덱스 전달

    // 출력
    cout << min_power_gap << '\n';
    
    return 0;
}