#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

vector<bool> is_prime(MAX + 1, true);   //인덱스에 해당하는 숫자가 소수인지 여부를 저장하는 벡터

// 에라토스테네스의 체를 이용해 소수를 찾는 함수
vector<bool> findPrime() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i*i; j <= MAX; j+=i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

//정수 n을 받고 그 숫자가 골드바흐 추측이 성립하는지 판별하는 함수
void checkGoldbach(int n) {
    for (int i = 3; i <= n/2; i++) {
        if (is_prime[i] && is_prime[n - i]) {
            cout << n << " = " << i << " + " << n-i << '\n';
            return;
        } // i와 n-i가 모두 소수일 경우 출력, 함수 종료
    }
    cout << "Goldbach's conjecture is wrong." << '\n'; // 루프를 모두 돌고 해당하는 경우가 없을 시 문구 출력
}

int main() {
    // 속도 향상 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    findPrime();

    while(1) {
        int n;
        cin >> n;
        if (n == 0) break;
        checkGoldbach(n);
    }
}