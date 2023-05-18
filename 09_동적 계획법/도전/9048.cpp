#include <iostream>
#include <vector>

using namespace std;

int countNumberOfCases(int n, int m, vector<int>& coins) {
    // dp[i]: i원을 만드는 경우의 수
    vector<int> dp(m + 1, 0);
    
    // 0원을 만드는 경우의 수는 1가지
    dp[0] = 1;
    
    // i: 고려하고 있는 동전 번호
    // j: 목표 금액
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= m; j++) {
            // i번 동전을 사용하지 않으면, 남은 금액 j를 만들어야 함
            // i번 동전 하나를 사용하면, 남은 금액 (j - coins[i])을 만들어야 함
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    
    return dp[m];
}

/**
 * dp[i] = 주어진 동전 종류를 사용해서 i원을 만드는 경우의 수
 *
 * dp[0] = 1 을 넣고 시작 (0원을 만드는 경우의 수 1로 생각)
 * 각 동전마다 해당 동전부터 만들어야 하는 금액(m)까지 돌리면서 해당 동전을 사용하기 전 금액의 경우의 수와 현재 경우의 수를 더함
 * 해당 동전 사용하기 전 금액의 경우의 수가 0이면 금액을 만들 수 없는 경우이지만, 어차피 더해도 값 변화는 없으므로 따로 고려하지 않음
 */

int main() {
    int t;
    
    cin >> t;
    while (t--) {
        int n, m;
        
        // 입력
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        cin >> m;

        // 연산
        int answer = countNumberOfCases(n, m, coins);

        // 출력
        cout << answer << "\n";
    }

    return 0;
}