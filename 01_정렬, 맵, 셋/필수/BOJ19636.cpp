/* 다이어트 전 체중 W, 일일에너지 섭취량 Ieat, 일일 기초대사량 Ispend, 일일 활동대사량 A==0
    다이어트 중 체중 &기초대사량 1일1회 변화, W += Ieat - (Ispend+A)
    일일 에너지 소비량 E = Ispend + A
    if Ieat - E > T(기초 대샤량 변화 역치)  Ispend += (Ieat-E)/2
    일일 기초 대사량 변화는 체중변화 후에 발생
    if W<0 or Ispend<0 낸시 사망
    D일간의 다이어트 후 I의 변화 고려 여부에 때른 예상 W & I, 원래 생활도 돌아갔을때 요요여부 계산*/

#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int W, I_b, T;
    int D, Ieat_d, A_d;
    //다이어트 전 W, Ieat, T입력
    cin >> W >> I_b >> T;
    //다이어트 기간D, 다이어트 Ieat, 다이어트 A입력
    cin >> D >> Ieat_d >> A_d;
    int Wn = W;
    int Ispend_d = I_b;
    int Wd = W;
    for (int i = 0; i < D; i++) {
        Wn += Ieat_d - (I_b + A_d);
        Wd += Ieat_d - (Ispend_d + A_d);
        if (abs(Ieat_d - (Ispend_d + A_d)) > T) 
            Ispend_d += floor((Ieat_d - (Ispend_d + A_d)) / 2.0); //floor 함수 내부는 double타입으로만 존재
    }
    //일일기초대사량 변화고려x W, Ispend출력(I는 입력된거 출력)
    //if W<0 or I<0 cout Danger Diet
    if (Wn <= 0){
        cout << "Danger Diet" << "\n";
    }
    else {
        cout << Wn << " " << I_b << "\n";
    }

    //일일기초대사량 변화고려 W, Ispend, 요요여부 출력
    //if W<0 or I<0 cout Danger Diet
    if ((Wd <= 0) || (Ispend_d <= 0)) {
        cout << "Danger Diet" << "\n";
    }
    else {
        if (Ispend_d < I_b) {
             cout << Wd << " " << Ispend_d << " " << "YOYO";
        }
        else {
            cout << Wd << " " << Ispend_d << " " << "NO";
        }
    }
    return 0;
}
