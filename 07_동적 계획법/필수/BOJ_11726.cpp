#include <iostream>
#include <vector>

using namespace std;

int countNumberOfCases(int n) {//채워야 하는 직사각형의 가로 길이n을 입력으로 받아 타일로 채우는 방법의 수를 리턴하는 함수
    const int MOD = 10'007;//마지막에 방법의 수를 mod로 나눈다.
    // dp[i]: 2xi 크기의 직사각형을 채우는 방법의 수
    vector<int> dp(n+1);//직사각형을 채우는 방법의 수를 저장할 벡터 선언
    
    dp[1] = 1; // 세로로 한 개만
    dp[2] = 2; // 세로로 두 개 or 가로로 두 개
    
    for (int i = 3; i <= n; i++) {//i가 3부터 n까지
        int vertical = dp[i - 1]; // 세로로 한 개 놓는 경우
        int horizontal = dp[i - 2]; // 가로로 두 개 놓는 경우
        dp[i] = (vertical + horizontal) % MOD;  // 오버플로우 방지를 위해 MOD 연산
    }
    
    return dp[n];//2*n의 직사각형을 채우는 방법의 수를 리턴
}

/**
 * 가장 마지막 세로줄을 채울 수 있는 방법을 살펴봅시다.
 * 1. 세로로 한 개를 놓는다.
 * 2. 가로로 두 개를 놓는다.
 *
 * 1번 방법으로 마지막 세로줄을 채울 경우, 남은 부분의 크기는 2 x (n-1)
 * 2번 방법으로 마지막 세로줄을 채울 경우, 남은 부분의 크기는 2 x (n-2)
 *
 * 따라서 2 x n 크기의 직사각형을 채우는 방법의 수는
 * d[i] = dp[i - 1] + dp[i - 2]
 */
int main() {
    int n;//정수 n 정의

    // 입력
    cin >> n;

    // 연산
    int answer = countNumberOfCases(n);//방법의 수 저장

    // 출력
    cout << answer;//구한 답을 출력

    return 0;//종료
}