#include <iostream>
#include <vector>

using namespace std;

//누적합을 계산하는 함수
void calSum(int n, vector<int> &sum){
    for(int i=2; i<=n; i++){
        sum[i] += sum[i-1]; //지금까지의 모든 숫자 합계 누적
    }
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j;
    vector <int> sum;

    //입력
    cin >> n >> m;
    sum.assign(n+1, 0); //초기화
    for(int i=1; i<=n; i++){
        cin >> sum[i];
    }

    //연산
    calSum(n, sum);
    
    //출력
    while(m--){
        cin >> i >> j;
        cout << sum[j]-sum[i-1] <<"\n";
    }

    return 0;
}