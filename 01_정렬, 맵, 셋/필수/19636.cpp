#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int w, bi, t, d, i, a;

    // 입력
    cin >> w >> bi >> t;
    cin >> d >> i >> a;

    int w1 = w;  // 첫번째 줄 계산

    int w2 = w;  // 두번째 줄 계산
    int bi2 = bi; //두번째 줄 계산을 위한 작업

    while (d--){
        w1 += i - (bi + a) ;

        w2 += i - (bi2 + a) ;
        if (abs(i - (bi2 + a)) > t){
            bi2 += floor((i - (bi2 + a))/2.0);
        }
    }


    if (w1 <= 0) // 일일 기초대사량이 고정인 경우이므로 고려 x
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << bi << "\n";



    if (w2 <= 0 || bi2 <= 0)
        cout << "Danger Diet\n";
    else{
        cout << w2 << " " << bi2 << " ";
        if (bi - bi2 > 0) 
            cout << "YOYO";
        else
            cout << "NO";
    }
}