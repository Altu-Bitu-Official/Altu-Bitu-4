#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 소수 여부 반환 함수: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) { // 정수 n을 전달받고 bool 타입의 벡터를 리턴
    vector<bool> is_prime(n + 1, true); // n+1 크기의 벡터 is_prime을 선언하고 true로 초기화
    is_prime[0] = is_prime[1] = false;  // 0과 1은 소수가 아니므로 제거
    for (int i = 2; i * i <= n; i++) {  // 2부터 제곱근 n까지 검사
        if (!is_prime[i]) { // 이미 제거된 수이면 탐색 X
            continue;
        }
        for (int j = i * i; j <= n; j += i) {   // i의 배수를 제거
            is_prime[j] = false;
        }
    }
    return is_prime;    // n(main 함수의 max_num)까지의 정수 중 소수만 구한 결과를 리턴
}

// n = a + b를 만족시키는 a 반환
int goldbach(int n, vector<bool>& is_prime) {   // 검증하고자 하는 짝수 정수 n과 소수 여부 판단을 위한 벡터 is_prime을 전달받음
    for (int a = 3; a <= n / 2; a += 2) {   // 3부터 n/2까지의 범위에 있는 홀수 검사
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        if (is_prime[a] && is_prime[n - a]) {   // a가 소수이면서 n-a도 소수이면 골드바흐의 추측 성립
            return a;   // n = a + b를 만족시키는 a 반환
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없으면 0 반환
    return 0;
}

/* [백준 6588: 골드바흐의 추측]
 * 1. 3보다 크거나 같고 n / 2보다 작거나 같은 소수 a를 오름차순으로 탐색한다.
 * 2. 1에서 찾은 a에 대하여 n - a(=b)도 소수이면 골드바흐의 추측이 성립한다.
 * 3. 골드바흐의 추측이 성립하면 a를, 성립하지 않으면 0을 반환한다.
 */

int main() {
    // 입력
    vector<int> arr;    // 입력받은 짝수 정수를 저장할 벡터 arr 선언
    int input;
    while (1) {
        cin >> input;   // 짝수 정수 n 입력받아서 input에 저장
        if (input == 0) {   // 0이 들어오면 입력 종료
            break;
        }
        arr.push_back(input);   // 입력받은 짝수 정수를 arr에 저장
    }

    // 연산
    int max_num = *max_element(arr.begin(), arr.end()); // arr에 저장된 요소들 중 최대값을 찾아서 max_num으로 저장
    vector<bool> is_prime = getPrimes(max_num); // getPrimes 함수에 max_num을 전달하고 그 결과를 벡터 is_prime에 저장

    for (int i = 0; i < arr.size(); i++) {  // arr에 저장된 짝수 정수 개수만큼 반복
        int a = goldbach(arr[i], is_prime); // goldbach 함수에 검증하고자 하는 짝수 정수와 소수 여부를 판단하는 is_prime 전달

        // 출력
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";    // n = a + b 형태로 출력
        }
        else {      // 존재하지 않으면
            cout << "Goldbach's conjecture is wrong.\n";    // "Goldbach's conjecture is wrong" 출력
        }
    }
    return 0;   // main 함수 종료
}