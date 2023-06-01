#include <iostream>
#include <vector>
 1914039-최유진
#include <algorithm>

using namespace std;


const int R = 0, G = 1, B = 2;

int paint(int n, vector<vector<int>>& houses) {
    // dp[i][j]: i번째 집은 j색으로 칠할 때, 1~i번 집까지 칠하는 최소 비용
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    for (int i = 1; i <= n; i++) {
        // (i-1)번 집은 남은 두 색상 중 하나로 칠해야 함
        dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R];
        dp[i][G] = min(dp[i - 1][B], dp[i - 1][R]) + houses[i][G];
        dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B];
    }
    
    return min({dp[n][R], dp[n][G], dp[n][B]});
}

/**
 * 1번집 부터 차례로 색칠합니다.
 * 만약 i번 집을 빨간색으로 칠한다면, (i-1)번 집을 초록색이나 파란색으로 칠했어야 합니다.
 * 초록색과 파란색 중 더 비용이 적게 드는 색을 선택하면 됩니다.
 */
int main() {
    int n;

    // 입력
    cin >> n;
    vector<vector<int>> houses(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B];
    }

    // 연산
    int answer = paint(n, houses);

    // 출력
    cout << answer;

    return 0;

int color[1001][3];

int main() {
    int N;
    int cost[3];// 칠할 때의 비용을 저장할 배열

    //값을 저장할 배열 선언, 0번째 집은 존재x->0으로 저장
    color[0][0] = 0; //빨간색으로 칠할 때
    color[0][1] = 0; //초록색으로 칠할때
    color[0][2] = 0; //파란색으로 칠할 때

    cin >> N;

    for (int i = 1; i <= N; i++){

        cin >> cost[0] >> cost[1] >> cost[2];//비용 입력 받음

        color[i][0] = min(color[i - 1][1], color[i - 1][2]) + cost[0];
        //빨간색으로 칠할 때: 이전 집이 파랑or초록 중 최소값+ 빨간색으로 칠하는 비용
        color[i][1] = min(color[i - 1][0], color[i - 1][2]) + cost[1];
        //초록색으로 칠할 때: 이전 집이 빨강or 파랑 중 최소값+초록으로 칠하는 비용
        color[i][2] = min(color[i - 1][1], color[i - 1][0]) + cost[2];
        //파란색으로 칠할 때: 이전 집이 빨강or초록 중 최소값+ 파랑으로 칠하는 비용
    }
    cout << min(color[N][2], min(color[N][0], color[N][1]));//빨강, 파랑, 초록 중 가장 작은 값을 출력

}