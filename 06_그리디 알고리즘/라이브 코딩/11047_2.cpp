// 동전 0

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, cnt = 0;
    cin >> n >> k;
    
    vector<int> coins(n);
    
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    
    for (int i=n-1; i>=0; i--){
        cnt += (k/coins[i]); // 동전 개수 갱신
        k %= coins[i]; // 남은 금액 갱신
    }
    cout << cnt;
    return 0;
}