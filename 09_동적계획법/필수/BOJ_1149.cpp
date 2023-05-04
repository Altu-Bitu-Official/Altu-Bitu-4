#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0, G = 1, B = 2;  // 빨강, 초록, 파랑을 가리킬 변수

int paint(int n, vector<vector<int>>& houses) { // 집의 개수와 색칠 비용 정보를 전달받아서 최소 비용을 리턴하는 함수
    // dp[i][j]: i번째 집은 j색으로 칠할 때, 1~i번 집까지 칠하는 최소 비용
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    for (int i = 1; i <= n; i++) {  // 집의 개수만큼 반복
        // (i-1)번 집은 남은 두 색상 중 하나로 칠해야 함
        dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R];  // i-1번째 집을 초록으로 칠하는 경우와 파랑으로 칠하는 경우 중 최소 비용 + i번째 집을 빨강으로 칠하는 비용
        dp[i][G] = min(dp[i - 1][B], dp[i - 1][R]) + houses[i][G];  // i-1번째 집을 파랑으로 칠하는 경우와 빨강으로 칠하는 경우 중 최소 비용 + i번째 집을 초록으로 칠하는 비용
        dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B];  // i-1번째 집을 빨강으로 칠하는 경우와 초록으로 칠하는 경우 중 최소 비용 + i번째 집을 파랑으로 칠하는 비용
    }
    
    return min({dp[n][R], dp[n][G], dp[n][B]}); // 최소 비용 리턴
}

/**
 * 1번집 부터 차례로 색칠합니다.
 * 만약 i번 집을 빨간색으로 칠한다면, (i-1)번 집을 초록색이나 파란색으로 칠했어야 합니다.
 * 초록색과 파란색 중 더 비용이 적게 드는 색을 선택하면 됩니다.
 */
int main() {
    int n;  // 집 개수 저장할 변수 선언

    // 입력
    cin >> n;   // 집 개수 입력받기
    vector<vector<int>> houses(n + 1, vector<int>(3, 0));   // 각 집을 빨강, 초록, 파랑으로 칠하는 비용 저장할 벡터 houses 선언
    for (int i = 1; i <= n; i++) {  // n개의 집에 대해
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B];    // 빨강, 초록, 파랑으로 칠하는 비용 입력받기
    }

    // 연산
    int answer = paint(n, houses);  // 집의 개수와 색칠 비용 정보를 paint 함수에 전달하고 결과를 answer에 저장

    // 출력
    cout << answer; // 결과 출력

    return 0;
}