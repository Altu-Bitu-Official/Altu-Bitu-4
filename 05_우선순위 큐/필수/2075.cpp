#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  priority_queue<int, vector<int>, greater<>> pq; //N번째 큰 수 := 최소 힙(top값이 현재 벡터 중 최솟값)
  int N;
  cin >> N;
  for(int i =0; i < N; i++){
    for(int j =0; j < N; j++){
      int X; cin >> X;
      pq.push(X);
      if(pq.size() > N){ 
        //메모리 초과 방지하기 위해서 N번째 큰 수까지만 입력받고, 입력받은 후에는 pq.top()을 바로 출력해준다.
        pq.pop();
      }
    }
  }
  int ans= pq.top();
  cout << ans << "\n";
}