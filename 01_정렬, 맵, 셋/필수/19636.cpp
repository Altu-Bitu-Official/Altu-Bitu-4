//19636 요요 시뮬레이션
#include <iostream>
#include <cmath>
using namespace std;
int start_weight, start_base, T; //다이어트 전 체중, 다이어트 전 섭취량, 기초대사량 변화 역치
int duration, eat, act; //다이어트 기간, 다이어트 기간 섭취량, 다이어트 일일 활동 대사량
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> start_weight >> start_base >> T;
  cin >> duration >> eat >> act;

  int weight1=start_weight, weight2=start_weight; //weight1: 기초대사량 고려X(항상 입력받은 기초대사량) weight2: 고려O(기초대사량 변화 반영)
  int diff_base=start_base; //기초대사량 변화 반영해주는 변수
  while(duration--){
    weight1+=eat-(start_base+act);
    weight2+=eat-(diff_base+act);
    if(abs(eat-(diff_base+act))>T) diff_base+=floor((eat-(diff_base+act))/2.0); //기초대사량 변화량 반영
  }
  if(weight1<=0||start_base<=0) cout << "Danger Diet\n";
  else cout << weight1 << " " << start_base << "\n";
  if(weight2<=0||start_base<=0||diff_base<=0) cout << "Danger Diet";
  else {
    cout << weight2 << " " << diff_base << " ";
    if(start_base>diff_base) cout << "YOYO\n";
    else cout << "NO\n";
  }
}