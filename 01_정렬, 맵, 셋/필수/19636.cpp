#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
    // 다이어트 전 체중, 다이어트 전 기초 대사량, 기초 대사량 변화 역치 
    int w, i_origin, t; 
    // 다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 일일 활동 대사량
    int d, i_diet, a;
    cin >> w >> i_origin >> t;
    cin >> d >> i_diet >> a;

    int i = i_origin;
    int add = i_diet - (i + a); // 일일 에너지 섭취량 - 일일 에너지 소비량
    int w1 = w + add * d;    

    // 출력 1: 기초대사량 고려 X
    if(w1 <= 0) {
        cout << "Danger Diet" << '\n';
    }
    else {
        cout << w1 << " " << i_origin << '\n';
    }

    while(d--) { // 다이어트를 하는 d일 동안
        // 체중 변화
        add = i_diet - (i + a);
        w += add;

        // 기초대사량 증가
        if (abs(add) > t) {
            i += floor((double)add / 2);
        } 
        
        // 사망 조건: 체중, 기초대사량 <= 0
        if(w <= 0 || i <= 0) { 
            cout << "Danger Diet" << '\n';
            return 0;
        }
    }
    
    // 출력 2: 기초대사량 고려 O
    cout << w << " " << i << " ";
    if(i_origin - i > 0) {
        cout << "YOYO";
    }
    else {
        cout << "NO";
    }

    return 0;
}