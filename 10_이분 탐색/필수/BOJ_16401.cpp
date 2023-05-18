#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 모든 조카에게 같은 길이를 나눠줄 수 있는지 확인
bool check(int length, int target, vector<int>& len) {
    // length: 과자 길이, target: 조카 수
    int cnt = 0; // 과자 조각 수
    for (int i = 0; i < len.size(); i++) {
        cnt += len[i] / length;
    }
    if (cnt >= target) return true; // 모든 조카에게 같은 길이로 나눠줄 수 있음
    return false;
}

int binarySearch(int left, int right, int target, vector<int>& len, int ans) {
    // mid로 과자 길이 갱신
    while (left <= right) {
        int mid = (left + right) / 2; 
        if (check(mid, target, len)) {
            ans = mid;
            left = mid + 1;
        }
        else  right = mid - 1;
    }
   return ans;
  }
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n; // 조카 수, 과자 수
    cin >> m >> n;
    vector <int> len(n, 0); // 과자 길이

    for (int i = 0; i < n; i++) {
        cin >> len[i];
    }
    sort(len.begin(), len.end());
    cout << binarySearch(1, len[n-1], m, len, 0);
    return 0;
}
