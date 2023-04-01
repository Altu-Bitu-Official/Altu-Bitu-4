#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N;
  priority_queue<int> pq; //우선순위 큐 선언
  cin >> N;
  while(N--){
    int x;
    cin >> x;
    if(x==0){ //0 입력받으면 아이들을 만난 것
      if(pq.empty()){ //줄 선물이 없다면
        cout << "-1\n"; //-1출력
      }
      else {
        int gift= pq.top(); //줄 선물은 현재 턴에서 우선순위 큐 안에 있는 top값과 동일
        pq.pop();
        cout << gift << "\n"; 
      }
    }
    else { //아니면 우선순위 큐 안에 선물 밀어넣기
      for(int i =0; i < x; i++){
        int new_gift;
        cin >> new_gift;
        pq.push(new_gift);
      }
    }
  }
  return 0;
}