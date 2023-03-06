#include <iostream>
#include <vector>
#include <cmath>
//n입력받을떄마다 소수 구하면 시간초과!!!!!!!!!!
using namespace std;
const int MAX = 1000000;

vector <bool> findPrime() {
    vector<bool> is_prime(MAX + 1, true); //소수 여부 저장
    is_prime[0] = is_prime[1] = is_prime[2] = false;
    for (int i = 3; i <= sqrt(MAX); i++) {
        if (is_prime[i]) { //소수가 아니면 탐색x
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
void getResult(int n, vector<bool> &is_prime){
    bool state = true;
    for (int i = 3; i <= n; i += 2) {
        if ((is_prime[i]) && (is_prime[n - i])) {
            cout << n << " = " << i << " + " << (n - i) << "\n";
            state = true;
            break;
        }
    }
    if (state != true) {
        cout << "Goldbach's conjecture is wrong." << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<bool> prime = findPrime();
    while (1) {
        //6 ≤ n ≤ 1000000
        cin >> n;
        if (n == 0) {
            break;
        }
        getResult(n, prime);
        //0 입력할떄까지 입력받아서 벡터값에 저장
        //vector에 저장된 값 앞에서 부터 가장 작은 소수 찾기
    }
    return 0;

}