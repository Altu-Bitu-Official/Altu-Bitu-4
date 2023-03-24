#include <iostream>
using namespace std;
// 판별하려는 숫자가 666이 포함된 숫자인지 알기 위해서는
// 1000으로 나눴을 때 나머지가 666인지 보면 된다.
// 만약 아니라면 자릿수를 줄여가며 판별한다.
// 이를 n에 도달할 때까지 반복한다.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans=0, cnt=0;
    cin >> n;

    while(cnt != n){
        ++ans;
        int tmp = ans;
        while(tmp != 0){
            if(tmp%1000 == 666){
                ++cnt;
                break;
            }
            else{
                tmp /= 10;
            }
        }
    }
    cout << ans;
}