//1655 중간을 말해요
//매번 정렬을 하면 O(n*nlogn)으로 시간 초과발생 --> 이전의 중간값을 이용하여 최대 힙, 최소 힙 선언.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  priority_queue<int> MaxQ; //최대 힙(내림차순)
  priority_queue<int, vector<int>, greater<int>> MinQ; //최소 힙(오름차)
  int N;
  cin >> N;
  while(N--){
    int X;
    cin >> X;
    if(MaxQ.size()==MinQ.size()) {
      MaxQ.push(X);
    } else {
      MinQ.push(X);
    }
    if(MaxQ.size()!=0 && MinQ.size()!=0 && MaxQ.top()>MinQ.top()) {
      int min_val= MinQ.top(); MinQ.pop();
      int max_val= MaxQ.top(); MaxQ.pop();
      MaxQ.push(min_val);
      MinQ.push(max_val);
    }
    cout << MaxQ.top() << "\n";
  }
}