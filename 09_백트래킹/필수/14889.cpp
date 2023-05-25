#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20; //문제 조건에 의해 n을 20으로 설정정
const int INF = 1e9; //minpowergap에 임시로 넣어둘 값

int n; 
int min_power_gap = INF; //초기화
int s[MAX_N][MAX_N]; //s: 능력치 입력 
bool is_start[MAX_N]; //is_start: 스타트 팀 or 링크 팀팀

//능력치 차이를 계산하는는 함수 
int calcTeamPowerGap() {
    int start_power = 0; //스타트 팀 능력치 초기화
    int link_power = 0; //스타트 팀 능력치 초기화 
    
    for (int i = 0; i < n - 1; i++) { //i: 0~n-2 
        for (int j = i + 1; j < n; j++) { //j: i+1~j
            int ssum = s[i][j] + s[j][i]; //ssum: 능력치를 저장하는 변수 
            
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

    return abs(start_power - link_power); //두 팀의 능력치 차이 리턴 
}

/**
 * 스타트팀원을 한명씩 뽑는다.
 * 중복 탐색을 막기 위해 팀원의 번호가 오름차순이 되도록 뽑는다.
 * ex) [1, 2]와 [2, 1]은 같은 케이스 이므로 [1, 2]만 탐색
 *
 * idx: 남은 사람들 중 가장 빠른 번호
 * cnt: 현재까지 뽑은 사람 수
 */
 
//남은 사람들 중 가장 빠른 번호 & 뽑은 사람 수 입력받아
//minpowergap고 is_start 배열을 수정 
void backtrack(int idx, int cnt) {
    // 재귀 호출 종료 조건: n/2명을 다 뽑은 경우
    if (cnt == (n / 2)) {
        // n/2명을 다 뽑은 경우 
        int power_gap = calcTeamPowerGap(); //그 때의 powergap 호출 
        min_power_gap = min(min_power_gap, power_gap); //둘 중 더 작은 값 뽑음 
        return;
    }
    
    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++) {//i: idx~n-1
        is_start[i] = true; //i번째 팀원 -> 스타트 팀원 
        backtrack(i + 1, cnt + 1); //그 다음 번호부터 다시 시작 
        is_start[i] = false; //돌려놓음 
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
    for (int i = 0; i < n; i++) { //i: 0~n-1 
        for (int j = 0; j < n; j++) { //j: 0~n-1 
            cin >> s[i][j]; //배열 s에 입력 
        }
    }

    // 연산
    is_start[0] = true; //0번에 있는 팀을 스타팀으로 결정 
    backtrack(1, 1); //1번부터 백트래킹 

    // 출력
    cout << min_power_gap << '\n'; //가장 작은 능력치 차이 출력
    
    return 0;
}