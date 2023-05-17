// 동전

#include <iostream>
#include <vector>
using namespace std;

int makingCost(vector<int> &coin, int cost, int m){
    vector<int> dp(cost+1, 0);
    dp[0] = 1;
    
    for (int i=0; i<m; i++){ // i번째 coin으로 채우기
        // dp[j] : 금액 j원까지 채우는 방법의 수
        for (int j=coin[i]; j<=cost; j++){ 
            dp[j] += dp[j-coin[i]]; // 이전 금액에 j번째 동전을 이용하여 채움
        }
    }
    return dp[cost];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, cost;
    
    cin >> n; // 시행횟수
    
    while (n--){
        cin >> m; // 동전 종류 수
        vector<int> coin(m,0);
        for (int i=0; i<m; i++){
            cin >> coin[i]; // 동전 종류 입력
        }
        cin >> cost;
        cout << makingCost(coin, cost, m) << '\n';
    }

    return 0;
}