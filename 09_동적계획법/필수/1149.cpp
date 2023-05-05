#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0, G = 1, B = 2;  //빨 초 파 배열 내 번호

int paint(int n, vector<vector<int>>& houses) {
    // dp[i][j]: i번째 집은 j색으로 칠할 때, 1~i번 집까지 칠하는 최소 비용
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    for (int i = 1; i <= n; i++) {  // (i-1)번 집은 남은 두 색상 중 하나로 칠해야 함
        dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R];  //이전 집은 초, 파 중 최소 비용 + 빨간색으로 칠하는 비용 
        dp[i][G] = min(dp[i - 1][B], dp[i - 1][R]) + houses[i][G]; //이전 집은 파, 빨 중 최소 비용 + 초록색으로 칠하는 비용
        dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B]; //이전 집은 빨, 초 중 최소 비용 + 파란색으로 칠하는 비용
    }
    
    return min({dp[n][R], dp[n][G], dp[n][B]}); //모든 집을 칠하는 비용의 최솟값
}

int main() {
    int n;  //집의 수

    // 입력
    cin >> n;
    vector<vector<int>> houses(n + 1, vector<int>(3, 0));   //집을 칠하는 비용을 저장할 벡터
    for (int i = 1; i <= n; i++) {
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B];    //각 집을 빨강, 초록, 파랑으로 칠하는 비용
    }

    // 연산
    int answer = paint(n, houses);

    // 출력
    cout << answer;

    return 0;
}