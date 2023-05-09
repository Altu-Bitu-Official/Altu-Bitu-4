#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

void binarySearch(long long left, long long right, int n, int m, vector<long long>& wait) {
    
}

int main() {
    int n, m;
    cin >> n >> m;
   long long wait[100001];

    for (int i = 0; i < n; i++) {
        cin >> wait[i]; // 심사대 마다 걸리는 시간 저장
    }
    sort(wait, wait+n); //오름차순으로 정렬

   long long right = m * wait[0];// 심사 시간이 제일 적은 데스크에 모든 사람이 검사 받을때:최대 값
   long long left = 1;//최소값
    
   long long mid;
   long long time = 0;
   long long people;

   while (left <= right) {
       people = 0;
       mid = (left + right) / 2;

       for (int i = 0; i < n; i++) {
           people += (mid / wait[i]); // mid시간에 검사할 수 있는 인원 수
       }

       if (people >= m) { // 주어진 인원m을 감당하기 충분함
           if (time > mid || time == 0) { // 최소시간일때 답 저장
               time = mid;
           }//값이 기존에 구했던 값보다 작다면 갱신
           right = mid - 1; //더 작아질 수 있는지 재탐색
       }
       else { //주어진 인원m을 감당하기엔 시간이 너무 짧음
           left = mid + 1; //범위를 키워서 재탐색
       }
   }
   cout << time; //최종값 출력



   return 0;
}
