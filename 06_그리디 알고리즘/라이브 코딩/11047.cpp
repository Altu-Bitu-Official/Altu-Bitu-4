// 동전 0

#include <iostream>
#include <vector>

using namespace std;

int countCoin(vector<int> coins, int n, int k){
    int sum = 0; // 지금까지 계산한 동전 합
    int cnt = 0; // 동전 개수
    int i = n-1; // 더하는 동전 값 인덱스
    while (1){
        if (sum + coins[i] == k){
            cnt += 1;
            return cnt;
        }
        else if (sum + coins[i] > k){
            i -= 1;
        }
        else{
            cnt += 1;
            sum += coins[i];
        }
        
    }
}

int main()
{
    int n, k, x;
    vector<int> coins;
    
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> x;
        coins.push_back(x);    
    }
    cout << countCoin(coins, n, k);
    return 0;
}