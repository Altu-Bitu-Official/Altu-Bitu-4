#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//이전 체중 w_before
//이후 체중 W_after @다이어트 기간 내내 변화
//다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량 i
//다이어트 기간 d
//일일 에너지 섭취량 eat
//일일 기초 대사량 basics  @다이어트 기간 내내 변화
//일일 활동 대사량 exercise
//기초 대사량 변화 역치 t

void first_diet(int d, int basics, int exercise, int w_after, int eat){
    //체중 계산
    w_after += (eat - basics - exercise)*d;

    if(w_after <= 0){       //체중이 0 이하 -> 사망
            cout << "Danger Diet" << "\n";
            return;
    }
    //사망하지 않았으면 (위험한 다이어트가 아니라면)
    cout << w_after << " " << basics << "\n";
}

void second_diet(int d, int basics, int exercise, int w_after, int eat, int i, int t){
    while(d--){
        //체중 계산
        w_after += eat - basics - exercise;
        //일일 기초 대사량 변화
        if (abs(eat - basics - exercise) > t){
            basics += (eat - basics - exercise)/2.0;
        }
        if(w_after <= 0 || basics <= 0){       //체중과 일일 기초 대사량이 0 이하 -> 사망
            cout << "Danger Diet" << "\n";
            return;
        }
    }
    //사망하지 않았으면 (위험한 다이어트가 아니라면) 요요 유무 판별
    if(i - basics > 0){
        cout << w_after << " " << basics << " " << "YOYO" << "\n"; 
    }
    else{
        cout << w_after << " " << basics << " " << "NO" << "\n"; 
    }
}
int main()
{
    int w_before, i, t;
    int d, eat, exercise;
    //입력
    cin >> w_before >> i >> t;
    cin >> d >> eat >> exercise;

    int basics = i;   //다이어트 전 일일 기초 대사량은 일일 에너지 섭취량과 같음
    int w_after = w_before;

    //일일 기초 대사량의 변화를 고려하지 않았을 때
    first_diet(d, basics, exercise, w_after, eat);

    //일일 기초 대사량의 변화를 고려했을 때
    second_diet(d, basics, exercise, w_after, eat, i, t);
}