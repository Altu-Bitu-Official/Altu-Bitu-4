#include <iostream>
#include <vector>

using namespace std;

//1차원 DP 배열 사용 
int countNumberOfCases(int n) {
    const int MOD = 10'007; //출력: 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지
    vector<int> dp(n+1); // dp[i]: 2xi 크기의 직사각형을 채우는 방법의 수
    
    dp[1] = 1; // 2x1 크기의 경우,세로로 한 개만
    dp[2] = 2; // 2x2 크기의 경우, 세로로 두 개 or 가로로 두 개
    
    for (int i = 3; i <= n; i++) { //i: 2xi 크기의 직사각형형
        int vertical = dp[i - 1]; //vertical: 세로로 한 개 
        int horizontal = dp[i - 2]; //horizontal: 가로로 두 개 놓는 경우
        dp[i] = (vertical + horizontal) % MOD; //재귀함수 사용 
                                               //오버플로우 방지를 위해 MOD 연산
        
        //점화식 세우기
        //가장 마지막 세로줄(i번째 줄)을 채우는 경우: 세로로 한 개 or 가로로 두 개
        //세로로 한 개: 남은 부분의 크기는 2 x (n-1)
        //가로로 두 개: 남은 부분의 크기는 2 x (n-2)
        //따라서 d[i] = dp[i - 1] + dp[i - 2]
    }
    
    return dp[n];
}

int main() {
    int n;

    //입력
    cin >> n;
    //연산
    int answer = countNumberOfCases(n);
    //출력
    cout << answer;

    return 0;
}