#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 각 자리수의 제곱의 합 계산 함수
int getSum(int n) {
    int total = 0, tmp;
    while (n != 0) {
        tmp = n % 10;
        n /= 10;
        total += tmp * tmp;
    }
    return total;
}
// 소수 여부 반환 함수: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n+1, true);
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
// 소수상근수 여부 반환 함수
bool is_valid(int n) {
    set<int> visited;
    visited.insert(n);
    while(1) {
        n = getSum(n);
        if (n == 1) {
            return true;
        }
        if (visited.find(n) != visited.end()) {
            return false;
        }
        visited.insert(n);
    }
}

// n보다 작거나 같은 소수상근수 벡터 반환
vector<int> solution(int n) {
    vector<bool> is_prime = getPrimes(n);
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && is_valid(i)) {
            result.push_back(i);
        }
    }
    return result;
}

/* [백준 9421: 소수상근수]
 * 상근수는 각 자리수의 제곱의 합을 재귀적으로 계산했을 때 1이 되는 수이다.
 * 즉, 각 자리수의 제곱의 합을 재귀적으로 계산했을 때
 * 이전에 나왔던 값이 다시 나온다면 그 수는 상근수가 될 수 없다.
 * 1. n보다 작거나 같은 모든 소수를 찾는다.
 * 2. n보다 작거나 같은 소수들이 상근수인지 판단한다.
 * 3. 소수이면서 상근수이면 결과값으로 추가한다.
 */

int main() {
    // 입력
    int n;
    cin >> n;
    
    // 연산
    vector<int> result = solution(n);

    // 출력
    for (int num : result) {
        cout << num << "\n";
    }
    return 0;
}
