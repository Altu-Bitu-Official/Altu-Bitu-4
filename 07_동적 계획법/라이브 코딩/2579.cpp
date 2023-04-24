// 2579
#include <iostream>
#include <vector>

using namespace std;

int maxScore(int n, vector<int> &score){
    // dp[i]: i번째 계단에 도착했을 때 점수의 최대값
    vector<int> dp(n+1, 0);
    
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    
    for (int i=3; i<=n; i++){
        // 한 칸 전에서 온 경우
        int one_step_before = dp[i-3] + score[i-1]; // 세 칸을 연속으로 밟을 수 X
        // 두 칸 전에서 온 경우
        int two_step_before = dp[i-2];
        
        dp[i] = max(one_step_before, two_step_before) + score[i];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> score(n+1, 0);
    
    for (int i=1; i<=n; i++){
        cin >> score[i];
    }
    
    int answer = maxScore(n, score);
    cout << answer;

    return 0;
}