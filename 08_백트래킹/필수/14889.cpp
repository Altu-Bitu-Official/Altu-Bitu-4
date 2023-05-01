#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
const int INF = 1e9;

int n;
int min_power_gap = INF;
int s[MAX_N][MAX_N];
bool is_start[MAX_N];

int calcTeamPowerGap() {
    int start_power = 0;
    int link_power = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int ssum = s[i][j] + s[j][i];
            
            // i와 j 모두 스타트 팀인 경우
            if (is_start[i] && is_start[j]) {
                start_power += ssum;
            }
            // i와 j 모두 링크 팀인 경우
            else if (!is_start[i] && !is_start[j]) {
                link_power += ssum;
            }
        }
    }

    return abs(start_power - link_power);
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
    if (cnt == (n / 2)) {
        int power_gap = calcTeamPowerGap();
        min_power_gap = min(min_power_gap, power_gap);
        return;
    }
    
    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++) {
        is_start[i] = true;
        backtrack(i + 1, cnt + 1);
        is_start[i] = false;
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
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    // 연산
    is_start[0] = true;
    backtrack(1, 1);

    // 출력
    cout << min_power_gap << '\n';
    
    return 0;
}
