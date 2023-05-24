#include <iostream>
#include <vector>

using namespace std;


int countNumberOfCases(int n) {
    const int MOD = 10'007;
    // dp[i]: 2xi 크기의 직사각형을 채우는 방법의 수
    vector<int> dp(n+1);
    
    dp[1] = 1; // 세로로 한 개만
    dp[2] = 2; // 세로로 두 개 or 가로로 두 개
    
    for (int i = 3; i <= n; i++) {
        int vertical = dp[i - 1]; // 세로로 한 개 놓는 경우
        int horizontal = dp[i - 2]; // 가로로 두 개 놓는 경우
        dp[i] = (vertical + horizontal) % MOD;  // 오버플로우 방지를 위해 MOD 연산
    }
    
    return dp[n];
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
    int n;

    // 입력
    cin >> n;

    // 연산
    int answer = countNumberOfCases(n);

    // 출력
    cout << answer;

    return 0;

int main() {

	int n;
	cin >> n;

	vector<int> tile;
	tile.push_back(1); //2*1 타일 채우는 방법=1가지
	tile.push_back(2);//2*2 차일 채우는 방법=2가지

	for (int i = 2; i < n; i++) {
		//n개의 타일을 채우는 방법은 n-1개의 타일 채우는 방법+n-2타일 채우는 방법
		tile.push_back((tile[i - 1] + tile[i - 2]) % 10007); 
	}
	cout << tile[n - 1];//한개씩 밀려서 저장됐으므로 n-1번째를 출력

	return 0;

}