#include <iostream>
#include <math.h>

using namespace std;

int noChange(int D, int W,int iBefore,int A ,int I){
    int addedWeight,consume;
    while(D--){
        consume=iBefore+A;
        addedWeight=I-consume;
        W+=addedWeight;
    }
    return W;
}

int main() {
    int w,iBefore,T,D,I,A;
    cin>>w>>iBefore>>T;//다이어트 전 체중, 다이어트 전 일일 에너지 섭취량/기초대사량,기초대사량 변화 역치
    cin>>D>>I>>A;//다이어트 기간,일일 에너지 섭취량,일일 활동 대사량
    int BMR = iBefore;
    int addedWeight,consume;
    string isYOYO;
    int noChangeWeight=noChange(D,w,BMR,A,I);
    if(noChangeWeight<=0){
        cout<< "Danger Diet"<<"\n";
    }else{
        cout <<noChangeWeight<<" "<<BMR<<"\n";

    }
    while(D--){
        consume=BMR+A;
        addedWeight=I-consume;
        w+=addedWeight;
        if(abs(addedWeight)>T){
            BMR+=floor(addedWeight/2.0);
        }
    }
    if(iBefore-(BMR+0)>0){
        isYOYO="YOYO";
    }else{
        isYOYO="NO";
    }
    if(BMR<=0||w<=0){
        cout<< "Danger Diet";
    }else{
        cout <<w<<" "<<BMR<<" "<<isYOYO;

    }

}
