#include <iostream>
#include <vector>

using namespace std;

/*
* 이분 탐색을 이용하여 나눠줄 수 있는 최대한 긴 과자의 길이를 찾아낸다.
*/

#define MAX_COOKIE 1000000000

int binarySearch(int m, vector<int> &cookie) {
    int right = MAX_COOKIE; // 과자의 최대 길이: 1000000000
    int left = 1; // 과자의 최소 길이: 1
    int res=0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        // mid 길이만큼씩 나눠주면 몇 명에게 나눠줄 수 있는지 세기
        for (int i = 0; i < cookie.size(); i++) {
            cnt += cookie[i] / mid;
        }
        if (cnt >= m) {
            left = mid + 1;
            res = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    int m, n;
    // 조카 수, 과자 수 입력
    cin >> m >> n;
    vector<int> cookie(n);
    // 막대과자 길이 입력
    for (int i = 0; i < n; i++) {
        cin >> cookie[i];
    }
    // 연산 & 출력
    cout << binarySearch(m, cookie);
    return 0;
}