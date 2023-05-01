// 11726 2*n 타일링 문제
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ll;
const int DIV = 10007;
ll solution(int n) {
    int dp[1001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i]= (dp[i-1]+dp[i-2]) % DIV;
    }
    ll answer = dp[n];
    return answer;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  cout << solution(n);
}
