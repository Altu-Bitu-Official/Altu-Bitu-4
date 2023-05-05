#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;//문제 조건에 의해 N은 20로 설정
const int INF = 1e9;//minpowergap에 임시로 넣어둘 값

int n;//축구를 하려고 모인 총 인원 정수n선언
int min_power_gap = INF;//minpowergap 초기화
int s[MAX_N][MAX_N];//능력치를 입력받을 정수배열 선언
bool is_start[MAX_N];//스타트 팀인지 링크 팀인지의 여부를 담을 bool배열 선언

int calcTeamPowerGap() {//능력치 차이를 알려주는 함수
    int start_power = 0;//스타트팀의 능력치 초기화
    int link_power = 0;//링크팀의 능력치 초기화
    
    for (int i = 0; i < n - 1; i++) {//0부터 n-2까지
        for (int j = i + 1; j < n; j++) {//i+1부터 n-1까지
            int ssum = s[i][j] + s[j][i];//능력치를 저장해두는 변수 ssum에 값 저장
            
            // i와 j 모두 스타트 팀인 경우
            if (is_start[i] && is_start[j]) {//두 값이 모두 1이면
                start_power += ssum;//스타트팀의 능력치에 ssum 덧셈
            }
            // i와 j 모두 링크 팀인 경우
            else if (!is_start[i] && !is_start[j]) {//두 값이 모두 0이면
                link_power += ssum;//링크팀의 능력치에 ssum 덧셈
            }
        }
    }

    return abs(start_power - link_power);//두 팀의 능력치의 차이 리턴
}

/**
 * 스타트팀원을 한명씩 뽑는다.
 * 중복 탐색을 막기 위해 팀원의 번호가 오름차순이 되도록 뽑는다.
 * ex) [1, 2]와 [2, 1]은 같은 케이스 이므로 [1, 2]만 탐색
 *
 * idx: 남은 사람들 중 가장 빠른 번호
 * cnt: 현재까지 뽑은 사람 수
 */
void backtrack(int idx, int cnt) {//남은 사람들 중 가장 빠른 번호와 현재까지 뽑은 사람 수를 입력하여 minpowergap과 is_start 배열을 수정하는 함수
    // 재귀 호출 종료 조건: n/2명을 다 뽑은 경우
    if (cnt == (n / 2)) {//n/2명을 다 뽑았을 때
        int power_gap = calcTeamPowerGap();//그 때의 powergap을 추출
        min_power_gap = min(min_power_gap, power_gap);//powergap과 minpowergap중 작은 값을 뽑는다.
        return;//종료
    }
    
    // [idx+1, idx+2, ..., n-1] 중에서 다음 팀원을 뽑음
    for (int i = idx; i < n; i++) {//i를 idx부터 n-1까지
        is_start[i] = true;//i번째 팀원을 스타트 팀원으로 만든다
        backtrack(i + 1, cnt + 1);//그 다음 번호부터에 대해 다시 스타트팀원 뽑기
        is_start[i] = false;//i번째 팀원을 링크 팀원으로 만든다
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
    cin >> n;//n을 입력받는다.
    for (int i = 0; i < n; i++) {//i가 0부터 n-1까지
        for (int j = 0; j < n; j++) {//j가 0부터 n-1까지
            cin >> s[i][j];//입력이 배열에 입력된다.
        }
    }

    // 연산
    is_start[0] = true;//0번이 있는 팀을 스타트팀으로 정한다.
    backtrack(1, 1);//1번부터 백트래킹 시작

    // 출력
    cout << min_power_gap << '\n';//찾아낸 가장 작은 능력치 차이를 출력한다.
    
    return 0;//종료
}