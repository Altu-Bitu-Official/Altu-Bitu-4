#include <iostream>
#include <cmath>

using namespace std;

// 다이어트 전 체중: w
// 출력 첫 번째 줄 체중: w1, 두 번째 줄 체중: w2
// 다이어트 전 일일 에너지 섭취량 = 일일 기초 대사량: i0
// 다이어트 기간 변화하는 일일 기초 대사량: i2
// 다이어트 기간: day
// 다이어트 기간 일일 에너지 섭취량: e_intake
// 다이어트 기간 일일 활동 대사량: active_rate

void yoyo(int w, int i0, int t, int day, int e_intake, int active_rate){
    int w1, w2, i2;
    w1 = w; w2 = w;
    i2 = i0;

    for (int i=0; i<day; i++){
        w1 += e_intake - (i0+active_rate);
        w2 += e_intake - (i2+active_rate);
        if (abs(e_intake - (i2+active_rate)) > t) {
            i2 += floor((e_intake-(i2+active_rate))/2.0);
        }
    }


    if(w1<=0 || i0<=0) cout << "Danger Diet\n";
    else cout << w1 << " " << i0 << "\n";

    if(w2<=0 || i2 <=0) cout << "Danger Diet\n";
    else {
        cout << w2 << " " << i2 << " ";
        if(w+i0-(i2+0)>w) cout << "YOYO";
        else cout << "NO";
    }

}

int main() {
    int w, i0, t, day, e_intake, active_rate;

    cin >> w >> i0 >> t;
    cin >> day >> e_intake >> active_rate;

    yoyo(w,i0,t,day,e_intake,active_rate);

    return 0;
}