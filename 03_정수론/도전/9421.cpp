#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<bool> findPrime(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(is_prime[i]) { // i가 소수라면
            for(int j = i*i; j <= n; j+= i) { // 처음 지워지는 수는 제곱수부터, i의 각 배수마다 반복
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

bool findHappy(int n) {
    vector<int> prev; // 계산한 수들을 저장할 벡터
    while(true) {
        if(find(prev.begin(), prev.end(), n) != prev.end()) { // 계산할 수가 저장된 수에 이미 있다면 -> 반복
            return false;
        }

        prev.push_back(n);
        string str = to_string(n);  // 문자열로 바꿔 한 자리씩 접근
        int sum = 0;
        for(int i = 0; i < str.size(); i++) {
            int num = str[i] - '0'; // 문자 -> 숫자
            sum += num*num;         // 각 자리 수의 제곱 더함
        }
        n = sum;                    // 합으로 다시 반복
        if(sum == 1) {
            return true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<bool> prime = findPrime(n);
    for(int i = 0; i < n; i++) {
        if(prime[i] && findHappy(i)) {
             cout << i << "\n";
        }
    }
    return 0;
}