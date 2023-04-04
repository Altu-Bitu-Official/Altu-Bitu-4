#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    //속도 10의 9승까지 가능하므로 int로 설정하면 범위 넘어감
    vector<long long> speed(n);

    for(int i=0; i<n; i++) {
        cin >> speed[i];
    }

    for(int i=n-2; i>=0; i--) {
        //앞 속도 뒤보다 커지도록 정수 배수배 해줌
        if(speed[i+1]>speed[i]) {
            speed[i]*=speed[i+1]/speed[i]+(speed[i+1]%speed[i]!=0);
        }
    }

    cout << speed[0];

    return 0;
}