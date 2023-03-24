#include <iostream>
#include <string>

using namespace std;

int solution(int n) { // 입력 제한: n은 1000 이하의 수
    if(n < 100) {                    // n이 100 미만이면
        return n;                    // 100 미만의 수는 모두 한수이므로 결과는 n
    }

    int cnt = 99;                    // n이 100 이상이면 결과에 99까지 저장하고
    for(int i = 100; i <= n; i++) {  // 100부터 탐색
        int first = i / 100;             // 백의 자리
        int second = i % 100 / 10;       // 십의 자리
        int last = i % 10;               // 일의 자리
        if(second * 2 == first + last) { // 등차수열이면 결과 증가
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << solution(n);

    return 0;
}