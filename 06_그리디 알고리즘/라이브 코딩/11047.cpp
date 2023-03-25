#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n, k;
    int result=0;
    cin >> n >> k;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for(int i=n-1; i>=0; i--) {
//        if(coins[i]<=k) {
//            while(k-coins[i]>=0) {
//                k-=coins[i];
//                result++;
//            }
//        }
        result+=k/coins[i];
        //4200%1000하면 k값 나머지 200으로 갱신
        k%=coins[i];
    }

    cout << result;

    return 0;
}