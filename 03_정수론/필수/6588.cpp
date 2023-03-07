#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 소수 여부 반환 함수: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

// n = a + b를 만족시키는 a 반환
int goldbach(int n, vector<bool> &is_prime) {
    for (int a = 3; a <= n / 2; a+= 2) {
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        if (is_prime[a] && is_prime[n - a]) {
            return a;
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
    vector<int> arr;
    int input;
    while(1) {
        cin >> input;
        if (input == 0) {
            break;
        }
        arr.push_back(input);
    }

    // 연산
    int max_num = *max_element(arr.begin(), arr.end());
    vector<bool> is_prime = getPrimes(max_num);

    for (int i = 0; i < arr.size(); i++) {
        int a = goldbach(arr[i], is_prime);

        // 출력
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";
        } else {      // 존재하지 않으면
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}
