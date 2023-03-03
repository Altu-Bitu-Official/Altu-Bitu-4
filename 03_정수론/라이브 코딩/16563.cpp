#include <iostream>
#include <vector>

const int MAX = 5000000; //k의 최대 범위
using namespace std;

vector<int> getPrimes() {
    vector<int> primes(MAX + 1, 0);
    for(int i = 2; i * i <= MAX; i++) {
        if(primes[i] != 0) { //소수가 아니면 탐색 X
            continue;
        }
        
        //j의 가장 작은 소인수는 i
        for(int j = i * i; j <= MAX; j += i) {
            if (primes[j] == 0) {
                primes[j] = i;
            }
        }
    }
    return primes;
}
vector<int> getPrimeFactors(int k, vector<int> &primes) {
    vector<int> factors; //소인수 저장

    while(primes[k] != 0) { //k가 소수가 될 때까지
        factors.push_back(primes[k]);
        k /= primes[k];
    }
    factors.push_back(k);
    return factors;
}
int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, k;
    cin>>n;

    //소수 경로 구하기
    vector<int> primes = getPrimes();

    //n개의 케이스 입력
    while (n--) { 
        cin >> k;

        //소인수분해
        vector<int> factors = getPrimeFactors(k, primes);

        //출력
        for (int num : factors) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}