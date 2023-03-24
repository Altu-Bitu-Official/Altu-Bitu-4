#include <iostream>
using namespace std;

/* X의 각 자리가 등차수열을 이루면, 그 수를 한수라고 함
* 자연수 n은 1000보다 작거나 같은 자연수
* 1부터 99까지는 무조건 한수
* 100 ~ 1000까지는 판별해주기
*/


int HanSoo(int n){

    if(n<100){ // 100미만은 무조건 다 한수
        return n; // 입력된 수 그대로 출력
    }

    else{
        int cnt = 99; // 100이상부터 한수 개수 판단해주는데 이미 99개의 한수를 가지므로 99로 초기화

        for(int i=100; i<=n; i++) {
            int hun = i / 100; //백의 자릿수
            int ten = (i/10) % 10; //십의 자릿수
            int one = i % 10; //일의 자릿수

            if((hun-ten) == (ten-one)){
                cnt++;
            }
        }
        return cnt;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << HanSoo(n);
    return 0;

}