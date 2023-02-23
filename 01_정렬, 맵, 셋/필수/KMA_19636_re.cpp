#include <iostream>
//#include <cmath> //내림 함수 floor 사용
using namespace std;

int main()
{
     // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int before_w, before_i; //다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량
    int t, d; //기초 대사량 변화 역치, 다이어트 기간
    int I, a;//다이어트 기간 일일 에너지 섭취량, 다이어트 기간 일일 활동 대사량
    int o, w; //일일 에너지 소비량, 몸무게

    //입력
    cin>> before_w >> before_i >> t >> d >> I >> a;

    //일일 기초 대사량 변화를 고려하지 않는 경우
    o = before_i + a;
    w = before_w + (I-o)*d;
    if (w <= 0)
        cout << "Danger Diet\n";
    else cout << w << ' ' << before_i << '\n';

    //일일 기초 대사량 변화를 고려하는 경우 
    int b = before_i;//기초대사량 초기값=다이어트 전 에너지섭취량
    w = before_w;//몸무게 초기화
    for(int i=0; i<d; i++){
        o = b + a;
        w += I-o;
        if(o-I>t) //abs(I-o)>t
            //b -= (o-I)/2;     //틀림-예제들은 맞게 출력되지만 백준에서 채점하면 틀림
            //b += (I-o)/2;     //틀림-마찬가지
            //b += floor(double(I-o)/2);   //맞음 
            b += double(I-o)/2;     //맞음
        if (w<=0||b<=0){ //죽으면 연산종료
            cout << "Danger Diet\n";
            return 0;
        }
    }
    //기초대사량 변화 고려한 예상체중, 일일기초대사량 출력
    cout << w << ' ' << b; 

    //다이어트 전 일일활동대사량은 0이므로
    //변화한 일일 기초대사량(b)가 다이어트 전 일일 에너지섭취량보다 작으면 체중이 증가함(YOYO)
    if(b<before_i) cout << " YOYO\n";
    else cout << " NO\n";

    return 0;
}