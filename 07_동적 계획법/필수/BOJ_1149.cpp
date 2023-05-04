#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0, G = 1, B = 2;//house 벡터에 쓸 색깔별 인덱스 미리 선언

int paint(int n, vector<vector<int>>& houses) {//최소비용 구하는 함수
    // dp[i][j]: i번째 집은 j색으로 칠할 때, 1~i번 집까지 칠하는 최소 비용
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    for (int i = 1; i <= n; i++) {
        // (i-1)번 집은 남은 두 색상 중 하나로 칠해야 함
        dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R];//현재 집은 R색으로 칠할 때 1부터 현재 집까지 칠하는 최소 비용은 현재의 비용과 지난 집의 G비용/B비용 중 최솟값을 더한 값
        dp[i][G] = min(dp[i - 1][B], dp[i - 1][R]) + houses[i][G];//현재 집은 G색으로 칠할 때 1부터 현재 집까지 칠하는 최소 비용은 현재의 비용과 지난 집의 R비용/B비용 중 최솟값을 더한 값
        dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B];//현재 집은 B색으로 칠할 때 1부터 현재 집까지 칠하는 최소 비용은 현재의 비용과 지난 집의 R비용/G비용 중 최솟값을 더한 값
    }
    
    return min({dp[n][R], dp[n][G], dp[n][B]});//마지막 집 색이 R G B 일 때 셋 중 비용의 최솟값을 리턴
}

/**
 * 1번집 부터 차례로 색칠합니다.
 * 만약 i번 집을 빨간색으로 칠한다면, (i-1)번 집을 초록색이나 파란색으로 칠했어야 합니다.
 * 초록색과 파란색 중 더 비용이 적게 드는 색을 선택하면 됩니다.
 */
int main() {
    int n;//집의 개수 n 선언

    // 입력
    cin >> n;//n 입력
    vector<vector<int>> houses(n + 1, vector<int>(3, 0));//각 집에 대해 빨강, 초록, 파랑으로 칠하는 비용을 저장할 수 있는 2차원 벡터 선언
    for (int i = 1; i <= n; i++) {//i가 1부터 n까지에 대해
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B];//각 집에 대해 RGB로 칠하는 비용 입력
    }

    // 연산
    int answer = paint(n, houses);//모든 집을 칠하는 비용의 최소값 구하기

    // 출력
    cout << answer;//답 출력

    return 0;//종료
}