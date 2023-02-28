//1946 신입 사원 
// 그리디 알고리즘으로 풀 수 있는 문제
#include <iostream>
#include <algorithm>
using namespace std;
int t; //테케 갯수

bool cmp(pair<int,int> p1, pair<int,int> p2) {
  return p1.first<p2.first; //서류순위 오름차순 정렬 
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    pair<int,int> info[100004]; //info.first=서류심사성적 info.second=면접성적
    for(int i = 0; i < n; i++) {
      cin >> info[i].first >> info[i].second; //서류, 면접
    }
    //cout << "\n서류 순위\n";
    
    sort(info, info+n, cmp); //서류 1등 골라내기
    
    //for(pair<int,int> pi : info){
    //  cout << pi.first << " " << pi.second << "\n";
    //}
    //서류 1등 지원자의 면접 성적 확인
    int standard_score=info[0].second; //서류 1등 면접 점수 기준점 저장
    int cnt=1; //서류 1등은 바로 채용
    // 바로 채용
    for(int i = 1; i < n; i++) {
      
      if(info[i].second<=standard_score) {
        //서류 1등 면접 점수를 기준 삼아 그것보다 지원자들 면접 점수가 더 높으면,
        cnt++;// 바로 채용
        standard_score = info[i].second; //기준점수는 방금 채용된 사람의 면접점수로 update
      }
    }
    
  cout << cnt << "\n";
    
  }
}