#include <iostream> // 입출력을 위한 헤더
#include <vector> // 벡터 객체를 사용하기 위한 헤더 
#include <algorithm> // 최대, 최소를 구하기 위한 알고리즘 라이브러리
using namespace std;
// 두 팀의 능력치 차이가 최소가 될 때의 최솟값 출력

const int MAX_N = 20; // 최대 인원 수를 상수로 선언 
const int INF = 1e9; // 능력치 차이의 최대를 큰 수로 표현한 상수 선언 

int n; // 사람 수 
int min_power_gap = INF; // 두 팀의 최소 능력치 저장하는 변수
int s[MAX_N][MAX_N]; // 사람별로 능력치가 저장된 행렬
bool is_start[MAX_N]; // 팀원 뽑은 후 체크하는 배열

int calcTeamPowerGap() { // 두 팀의 능력치 차이를 구하는 함수
    int start_power = 0; // 스타트 팀의 능력치
    int link_power = 0; // 링크 팀의 능력치

    for (int i = 0; i < n - 1; i++) { // 행렬 표에서 
        for (int j = i + 1; j < n; j++) { // i번과 j번이 중복된 조합이 되지 않도록 ( j = i+1)
            int ssum = s[i][j] + s[j][i]; // i번과 j번이 같은 팀인 경우 능력치 계산한 값

            if (is_start[i] && is_start[j]) { // i와 j 모두 스타트 팀인 경우
                start_power += ssum; // 스타트 팀의 능력치에 더함
            }
            else if (!is_start[i] && !is_start[j]) {  // i와 j 모두 링크 팀인 경우
                link_power += ssum; // 링크 팀의 능력치에 더함
            }
        }
    }

    return abs(start_power - link_power); // 두 팀의 능력치 차이 값 반환
}
/**
 * 스타트팀원을 한명씩 뽑는다.
 * 중복 탐색을 막기 위해 팀원의 번호가 오름차순이 되도록 뽑는다.
 * ex) [1, 2]와 [2, 1]은 같은 케이스 이므로 [1, 2]만 탐색
 *
 * idx: 남은 사람들 중 가장 빠른 번호
 * cnt: 현재까지 뽑은 사람 수
 */
void backtrack(int idx, int cnt) { // 백트래킹을 활용한 가지치기 함수
    // 재귀 호출 종료 조건: n/2명을 다 뽑은 경우
    if (cnt == (n / 2)) { // n/2명을 다 뽑은 경우 
        int power_gap = calcTeamPowerGap(); // 능력치 차이는 위의 연산 함수의 반환값
        min_power_gap = min(min_power_gap, power_gap);
        // 새로 구한 min_power_gap과 위에서 구한 power_gap 중 최솟값을 갱신 후 
        return; // 함수 종료
    }

    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++) { // 중복이 되지 않도록
        is_start[i] = true; // 뽑은 사람의 번호 체크 
        backtrack(i + 1, cnt + 1); // 다음 번호의 함수 재귀 호출
        is_start[i] = false; // 해당 뽑은 번호 반납
    }
}

/**
 * 스타트: [1, 2], 링크: [0, 3]인 경우와
 * 스타트: [0, 3], 링크: [1, 2]인 경우는 같다.
 * 특정 사람이 있는 팀 / 없는 팀으로만 구별하면 된다.
 * 0번이 있는 팀과 없는 팀으로 구별하자. 그리고 0번이 있는 팀을 스타트팀이라고 부르자.
 * 스타트팀을 뽑는 모든 조합을 전부 시도해본다.
 */
int main() { // 가장 먼저 실행되는 main 함수 
    // 입력
    cin >> n; //  인원수 입력 
    for (int i = 0; i < n; i++) { // 열별로
        for (int j = 0; j < n; j++) { // 행별로 
            cin >> s[i][j]; // 각 사람마다 능력치 입력
        }
    }
    // 연산
    is_start[0] = true; // 팀원 선택하는 배열 0번 인덱스는 사용 X -> true로 설정
    backtrack(1, 1); // 함수의 초기 input값 대입
    // 출력
    cout << min_power_gap << '\n'; // 두 팀의 능력 차이 최소값 출력

    return 0; // main 함수 종료
}