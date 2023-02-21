//아직 많이 미완성이지만 일단 제출하겠습니다ㅠ
//추후 주석써서 추가제출 하겠습니다!
#include <iostream>
using namespace std;

int main()
{
     // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int before_w, before_i, t, d, I, a;
    int o; //일일 에너지 소비량
    int w;
    //입력
    cin>> before_w >> before_i >> t >> d >> I >> a;

    //일일 기초 대사량 변화를 고려하지 않는 경우
    w = before_w + (I - before_i)*d;
    if (w <= 0)
        cout << "Danger Diet" << '\n';
    else cout << w << ' ' << before_i;

    //일일 기초 대사량 변화를 고려하는 경우 
    int b = before_i;//기초대사량 초기값=다이어트 전 에너지섭취량
    int w = before_w;
    /*
    if (w>0||b>0){
        for(int i; i<d; i++){
            o = b + a;
            w += I-o;
            if(o-I>t)
                b -= (o-I)/2;
        }
    }
    */
   /*
    for(int i; i<d; i++){
        if(w>0||b>0){
            o = b + a;
            w += I-o;
            if(o-I>t)
                b -= (o-I)/2;
        }
        else {
            cout << "Danger Diet";
            break;
        }
    }
    cout << w << ' ' << b << ' ';
    */
    /*
    if(yoyo){
        
    }
    */

    return 0;
}