#include <iostream>
#include <vector>

using namespace std;

/*
* 이분 탐색을 이용하여 나눠줄 수 있는 최대한 긴 과자의 길이를 찾아낸다.
*/

#define MAX_COOKIE 1000000000

// 조카의 수 m 과 과자길이가 저장된 벡터 cookie를 입력받아서
// 이분탐색을 이용한 계산을 거쳐서
// 조카 1명에게 줄 수 있는 막대 과자의 최대 길이를 반환한다
int binarySearch(int m, vector<int> &cookie) {
    int right = MAX_COOKIE; // 과자의 최대 길이: 1000000000
    int left = 1; // 과자의 최소 길이: 1
    int res=0;  // 정답

    while (left <= right) { 
        int mid = (left + right) / 2;   // 중간값 mid
        int cnt = 0;  //  mid 길이만큼씩 나눠주면 cnt 명에게 나눠줄 수 있다

        // cnt값 구하기
        for (int i = 0; i < cookie.size(); i++) {   // i가 0부터 과자개수-1까지 과자개수만큼 반복
            cnt += cookie[i] / mid;     // 각 쿠키들을 mid 값으로 나눈 몫의 합만큼 나눠줄 수 있다
        }

        if (cnt >= m) {     // mid 길이의 과자를 나눠줄 수 있는 사람의 수가 조카의 수보다 크거나 같을 때
            left = mid + 1;     // 다음에는 mid 값보다 큰 범위에서 탐색
            res = mid;  // 결과값에 mid 저장
        }
        else{   // mid 길이의 과자를 나눠줄 수 있는 사람의 수가 조카의 수보다 작을 때
            right = mid - 1;    // 다음에는 mid 값보다 작은 범위에서 탐색
        }
    }
    return res; //조카 1명에게 줄 수 있는 막대 과자의 최대 길이
}

int main() {
    int m, n;
    // 조카 수, 과자 수 입력
    cin >> m >> n;
    vector<int> cookie(n);  // 막대과자 길이 저장할 벡터
    // 막대과자 길이 입력
    for (int i = 0; i < n; i++) {
        cin >> cookie[i];
    }
    // 연산 & 출력
    cout << binarySearch(m, cookie);
    return 0;
}