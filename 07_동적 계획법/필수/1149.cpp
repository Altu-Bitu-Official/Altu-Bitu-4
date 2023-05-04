#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0, G = 1, B = 2;

int paint(int n, vector<vector<int>>& houses) {  // dp[i][j]: i번째 집은 j색으로 칠할 때, 1~i번 집까지 칠하는 최소 비용
    vector<vector<int>> dp(n + 1, vector<int>(3, 0)); //vector dp 선언해주기
    
    for (int i = 1; i <= n; i++) { // (i-1)번 집은 남은 두 색상 중 하나로 칠해야 함
        dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R]; //red로 칠할때 
        dp[i][G] = min(dp[i - 1][B], dp[i - 1][R]) + houses[i][G]; //green으로 칠할때
        dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B]; //blue로 칠할때
    }
    
    return min({dp[n][R], dp[n][G], dp[n][B]}); //3개의 dp 값을 비교해 가장 작은 걸 고른다.
}

int main() {
    int n;

    // 입력
    cin >> n;
    vector<vector<int>> houses(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B]; //입력 받기
    }

    // 연산
    int answer = paint(n, houses);

    // 출력
    cout << answer;

    return 0;
}