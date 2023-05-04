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
        for (int j = i + 1; j < n; j++) { //중복 방지를 위해 무조건 j는 i보다 크게 해주기
            int ssum = s[i][j] + s[j][i]; // i와 j를 뽑아 계산해주기
            
            if (is_start[i] && is_start[j]) { //i와 j가 start team인 경우
                start_power += ssum;
            }

            else if (!is_start[i] && !is_start[j]) { //i와 j가 link team인 경우
                link_power += ssum;
            }
        }
    }

    return abs(start_power - link_power); //두 팀의 차를 구해주기
}

void backtrack(int idx, int cnt) {
    if (cnt == (n / 2)) { //n/2명을 다 뽑았을 경우 실행 -> return에 의해 재귀가 종료됨
        int power_gap = calcTeamPowerGap(); //두 팀간의 차이를 저장
        min_power_gap = min(min_power_gap, power_gap); //두 개를 비교해 제일 적은 걸 저장
        return;
    }
    
    for (int i = idx; i < n; i++) { //팀원을 뽑기 위한 계산
        is_start[i] = true;
        backtrack(i + 1, cnt + 1);
        is_start[i] = false;
    }
}

int main() {
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j]; //입력받음
        }
    }

    // 연산
    is_start[0] = true;
    backtrack(1, 1);

    // 출력
    cout << min_power_gap << '\n';
    
    return 0;
}