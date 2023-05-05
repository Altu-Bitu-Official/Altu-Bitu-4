#include <iostream>
#include <vector>
using namespace std;

int n, min_power = 100*10*2;    //차이 최대 100, 최소 0 * 한 팀 최대 10명 * 한 쌍 당 두 번 더하므로 2배
vector<vector<int>> power;
vector<int> team_a, team_b;
vector<bool> is_used;

//두 팀의 힘의 차이를 구하는 함수
int calcPower() {
    int pa = 0, pb = 0, idx = 0;

    for (int i = 1; i <= n; i++) {
        bool is_same = false;
        for (int j = 0; j < n/2; j++) {
            if (team_a[j] == i) {
                is_same = true;    //팀 a의 멤버와 반복문의 i가 같을 때
                break;
            }
        }
        if (!is_same) {     //다르면 팀에 없는 멤버이므로 다른 팀에 넣어주기.
            team_b[idx++] = i;
        }
    }

    for (int i = 0; i < n/2-1; i++) {
        for (int j = i+1; j < n/2; j++) {
            pa += power[team_a[i]][team_a[j]] + power[team_a[j]][team_a[i]];
            pb += power[team_b[i]][team_b[j]] + power[team_b[j]][team_b[i]];
        }
    }

    return abs(pa-pb);
}

//백트래킹을 수행하는 함수
void backtrack(int cnt) {
    if (cnt == n/2) {   //한 팀을 다 채웠을 때
        min_power = min(calcPower(), min_power);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (is_used[i] || (cnt != 0 && team_a[cnt-1] >= i)) {   //이미 사용한 수 + 오름차순 어김 방지
            continue;
        }
        team_a[cnt] = i;
        if (team_a[0] >= 2) {   //첫 수가 1이면 모든 조합 커버 가능 -> 2부터는 제외.
            return;
        }
        is_used[i] = true;
        backtrack(cnt+1);

        is_used[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    cin >> n;

    power.assign(n+1, vector<int>(n+1, 0));
    team_a.assign(n/2, 0);
    team_b.assign(n/2, 0);
    is_used.assign(n+1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> power[i][j];
        }
    }

    backtrack(0);

    //출력
    cout << min_power;
}