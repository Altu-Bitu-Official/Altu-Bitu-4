// 10815 숫자 카드
/* 
    sequential search로 풀면 시간초과가 일어납니다.
    탐색 범위의 중간=mid값을 중심으로 왼쪽/오른쪽으로 탐색 범위를 나누어, key값을 
    찾을 때까지 탐색을 계속 합시다.
    이분탐색으로 풀어야 하는 대표적인 문제
*/ 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int SIZE = 500001;
const int FOUND = 1;
const int MV_RIGHT = 0;
const int MV_LEFT = -1;

ll cards[SIZE];

int chk(int &key, int &mid){
  if(cards[mid] == key){
    return FOUND;
  }
  else if(cards[mid] < key) { //찾으려는 키 값보다 현재 위치의 값이 더 작을 때
    return MV_RIGHT; // 탐색 범위를 오른쪽으로 줄이기
  }
  else { // 찾으려는 키 값보다 현재 위치의 값이 더 클 때
    return MV_LEFT; // 탐색 범위를 왼쪽으로 줄이기
  }
}

int binarySearch(int &key, int &N){
  int lo = 0;
  int hi = N-1;
  int mid;
  while(lo <= hi){
    mid = (lo + hi)/2;
    if(chk(key, mid) == FOUND) {
      return 1;
    }
    else if(chk(key, mid) == MV_RIGHT){
      lo = mid + 1; // 탐색 범위 오른쪽으로 이동
    }
    else { // MV_LEFT
      hi = mid - 1; // 탐색 범위 왼쪽으로 이동
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N, M;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> cards[i];
  }
  sort(cards, cards+N); // 이분탐색하기 전, 오름차순 정렬을 해야함을 유의합시다.
  cin >> M;
  for(int i = 0; i < M; i++){
    int key;
    cin >> key;
    cout << binarySearch(key, N) << " ";
  }
}