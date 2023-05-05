#include <iostream>
#include <vector>

using namespace std;

//n과 세로 좌표별 직사각형을 채우는 방법의 수가 담긴 벡터를 입력받고, 전체 채우는 방법의 수를 출력하는 함수 
int maxTile(int n, vector<int> tile) {
    vector<int> dp(n+1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%10007;  //10007로 나눈 나머지가 필요.
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> tile (n+1, 0); 

    int answer = maxTile(n, tile);
    //출력
    cout << answer;
}