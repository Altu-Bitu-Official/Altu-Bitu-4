#include <iostream>
#include <vector>

using namespace std;

int maxScore(int n, vector<int> &score) {
    // dp[i]: i번째 계단에 도착했을 때 점수의 최대값
    vector<int> dp(n + 1, 0);

    // 두 번째 계단까지는 모든 칸을 밟고 오는 것이 최대
    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (int i = 3; i <= n; i++) {
        // 한 칸 전에서 온 경우 vs. 두 칸 전에서 온 경우
        int one_step_before = dp[i - 3] + score[i - 1]; // 세 칸을 연속으로 밟을 수 없으므로
        int two_steps_before = dp[i - 2];
        dp[i] = max(one_step_before, two_steps_before) + score[i];
    }

    return dp[n];
}

int main() {
    int n;

    // 입력
    cin >> n;
    vector<int> score(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    // 연산
    int answer = maxScore(n, score);

    // 출력
    cout << answer;

    return 0;
}