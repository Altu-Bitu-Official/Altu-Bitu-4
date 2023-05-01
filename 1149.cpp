// RGB 거리
// dp문제는 패턴을 찾는 것임을 유의하며, 어떤 상태에서 직전의 상태를 보장/혹은 보장하지 않는다는 조건이
// 문제 조건에 나오면 dp를 먼저 생각하자.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    int dp[1001][3];
    // *--dp 테이블 정의--*
    /*
    dp[i][0] = i번 집을, 빨간색으로 칠했을 때 드는 비용의 최솟값
    dp[i][1] = i번 집을, 초록색으로 칠했을 때 드는 비용의 최솟값
    dp[i][2] = i번 집을, 파란색으로 칠했을 때 드는 비용의 최솟값
    */
   cin >> N;
   int cost[3]; // 매 줄 입력받을 때마다 RGB cost순서대로 입력받을 변수
   dp[0][0] = dp[0][1] = dp[0][2]= 0; 
   //0번 집은 존재하지 않으므로 0으로 초기화
   for(int i = 1; i <= N; i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        dp[i][0] = min(dp[i-1][1], dp[i-1][2])+cost[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2])+cost[1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1])+cost[2];
   }
   int ans = min(dp[N][0], min(dp[N][1], dp[N][2]));
   cout << ans;
}