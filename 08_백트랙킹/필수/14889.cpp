#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;   // 인원 최댓값 20
const int INF = 1e9;

int n;  // 축구하러 모인 인원
int min_power_gap = INF;    // 스타트 팀과 링크 팀의 능력치의 차이의 최솟값
int s[MAX_N][MAX_N];    // i와 j가 같은 팀에 속했을 때 팀에 더해지는 능력치
bool is_start[MAX_N];   // 스타트 팀이면 1, 링크 팀이면 0

// 스타트팀과 링크팀의 능력치 차이 구한다
int calcTeamPowerGap() {
    int start_power = 0;    // 스타트 팀의 능력치
    int link_power = 0;     // 링크 팀의 능력치
    
    for (int i = 0; i < n - 1; i++) {   // i가 0부터 n-2까지 n-1번동안
        for (int j = i + 1; j < n; j++) {   // j가 0부터 n-1까지 n번동안
            int ssum = s[i][j] + s[j][i];   // i와 j가 한팀에 있을때 팀에 더해지는 능력치(Sij와 Sji를 더한 값)
            
            // i와 j 모두 스타트 팀인 경우
            if (is_start[i] && is_start[j]) {
                start_power += ssum;    // 스타트 팀에 ssum 만큼 더해짐
            }
            // i와 j 모두 링크 팀인 경우
            else if (!is_start[i] && !is_start[j]) {
                link_power += ssum;    // 링크 팀에 ssum 만큼 더해짐
            }
        }
    }

    return abs(start_power - link_power);   // 절댓값 함수를 이용해서 스타트 팀과 링크 팀의 능력치 차를 반환함
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
    if (cnt == (n / 2)) {   // cnt 가 n/2가 되면
        // 현재 두 팀의 능력치 차이 구한다
        // 전단계까지의 두 팀의 능력치 차이의 최솟값과 비교해서 두 팀의 능력치 차이의 최솟값을 확인한다
        int power_gap = calcTeamPowerGap(); 
        min_power_gap = min(min_power_gap, power_gap);  
        return;
    }
    
    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++) { // i가 idx부터 n-1까지
        is_start[i] = true; // i를 스타트 팀에 넣는다
        backtrack(i + 1, cnt + 1);  // 다음단계
        is_start[i] = false;    // 다음에 쓸 수 있도록 i를 초기화
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
    cin >> n;   // 인원 입력받음
    for (int i = 0; i < n; i++) {   // i가 0부터 n-1까지 n번동안
        for (int j = 0; j < n; j++) {   // j가 0부터 n-1까지 n번동안
            cin >> s[i][j]; //  i와 j가 같은 팀에 속했을 때 팀에 더해지는 능력치 입력받음
        }
    }

    // 연산
    is_start[0] = true; // 0번이 있는 팀을 스타트팀으로 부르기로 했으니까
    backtrack(1, 1);    // 백트래킹 시작

    // 출력
    cout << min_power_gap << '\n';  // 스타트 팀과 링크 팀의 능력치의 차이의 최솟값 출력
    
    return 0;
}