//
// Created by dduoy on 2023-02-21.
//
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int W, basic1, T, D, In, Out;

    cin >> W >> basic1 >> T;
    cin >> D >> In >> Out;

    int res1 = W;
    int res2 = W;
    int basic2 = basic1;

    for(int i=0; i<D; i++){
        res1 += In - (basic1 + Out);
        res2 += In - (basic2 + Out);
        if( abs(In-(basic2 + Out)) > T)
            basic2 += floor((In-(basic2 + Out))/2.0);
    }

    if(res1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << res1 << " " << basic1 << "\n";

    if(res2 <=0 || basic2 <=0)
        cout << "Danger Diet\n";
    else{
        cout << res2 << " " << basic2 << " ";
        if(basic1 - basic2 > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
}

/*
 * 다이어트 전 체중 = W0
 * 에너지 섭취량 = I0
 * 기초대사량 = I0
 * 활동 대사량 A0 = 0
 *
 * 다이어트 중
 * 에너지 섭취량 = I
 * 활동 대사량 = A
 *
 * 1) 기초대사량 변화 반영 X
 * res1 += E섭취량 - (기초대사량 + 활동대사량)
 *
 * 2) 기초대사량 변화 반영 O
 * res2 += E섭취량 - (기초대사량 + 활동대사량)
 * 만약 |res2| > T라면 기초대사량은 (res2)/2만큼 더해짐
 *
 * 체중 <= 0 이거나 기초대사량 <=0 이면 Danger Diet 출력
*/