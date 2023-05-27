// 9084 동전
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; //테케 갯수
    int N; // 동전 종류 개수
    vector<int> coin(N); // 해당 종류에 해당하는 동전 개수 담는 배열, 오름차순으로 정렬되어있습니다.
    int M; // 만들어야 하는 금액(가치합)
    /*
    -- 해당 dp 테이블은 1로 초기화 셋팅 되어있고, 
    그다음 동전 가치가 자기보다 큰 가치가 나오면
     그 가치수만큼의 dp를 더해가며 업데이트한다. --
    */
   cin >> T;
    while(T--){
        vector<int> dp(10001); //dp테이블 생성
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> coin[i];
        }
        cin >> M; 
        dp[0] = 1;
        for(int i = 0; i < N; i++) {
            for(int j = coin[i]; j <= M; j++){
                dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[M] << "\n";
    }
}