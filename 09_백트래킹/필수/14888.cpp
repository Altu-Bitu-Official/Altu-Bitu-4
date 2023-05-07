//14888 연산자 끼워넣기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve(int arr[], int op[], int &N, vector<int> &ans, int depth, int cur){
  if(depth == N-1) {
    ans.push_back(cur);
  }
  for(int i = 0; i < 4; i++) {
    if(op[i]==0) continue; 
    //연산자 인벤토리에서 해당 연산자가 0개 남아있다면, 다음 후보군으로 이동
    //연산수행
    int tmp = cur;
    if(i==0){
        cur += arr[depth+1];
    }
    if(i==1){
        cur -= arr[depth+1];
    }
    if(i==2) {
        cur *= arr[depth+1];
    } 
    if(i==3) {
        cur /= arr[depth+1];
    }
    op[i]--; //연산자 인벤토리에서 방금 수행한 연산자 개수 하나 감소
    solve(arr, op, N, ans, depth+1, cur);
    //중요, 다시 바로 위 부모노드 상태에서의 연산자 인벤토리 값, cur값으로 바꿔줘야함.
    op[i]++; 
    cur = tmp;
  } 
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N;
  int arr[14], op[4];
  vector<int> ans; //정답 후보군 담을 ans배열
  //최댓값은 *max_element(ans.begin(), ans.end())/최솟값은 *min_element(ans.begin(), ans.end());
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < 4; i++) {
    cin >> op[i];
  }
  solve(arr, op, N, ans, 0, arr[0]);
  sort(ans.begin(), ans.end());
  //for(auto x: ans) cout << x << " ";
  cout << *max_element(ans.begin(), ans.end()) << "\n" << *min_element(ans.begin(), ans.end());
}