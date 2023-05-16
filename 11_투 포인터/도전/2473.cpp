// 2473 세 용액
/*
  인풋값으로 주어진 배열을 오름차순 정렬 후에,
  fix 값을 하나 정한 후 s포인터 값은 그 다음 fix+1의 인덱스값으로 지정합니다.
  이후에는 2470 두 용액의 풀이와 유사합니다 : 2470 두 용액에 대한 풀이 포스팅:
  [https://velog.io/@christer10/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%B1%EC%A4%80-2470-%EB%91%90-%EC%9A%A9%EC%95%A1]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f;

void solve(int &N, vector<ll> &liq, vector<ll> answer){
  ll candid_diff =INF;
  for(int fix = 0; fix < N-2; fix++) {
    int s = fix + 1;
    int e = N-1;
    while(s < e){
      ll sum = liq[fix] + liq[s] + liq[e];
      if(candid_diff > abs(sum)){
      candid_diff = abs(sum);
      answer[0] = liq[fix];
      answer[1] = liq[s];
      answer[2] = liq[e];
      }
      if(sum == 0) {
        break;
      }
      else if(sum < 0){
        s++;
      }
      else {
        e--;
      }
    }
  }
  cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N;
  cin >> N;
  vector<ll> liq(N, 0);
  for(int i = 0; i < N; i++){
    cin >> liq[i];
  }
  sort(liq.begin(), liq.end());
  vector<ll> answer(3); // 세 용액의 정답을 가져올 벡터 배열
  solve(N, liq, answer);
}