/* 정수의 각 자리가 등차수열
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
*/
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