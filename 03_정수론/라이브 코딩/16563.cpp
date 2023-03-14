#include <iostream>
#include <vector>

const int MAX=5000000;
using namespace std;

//각 숫자 소인수 찾아서 넣기
vector<int> getPrimes() {
    vector<int> primes(MAX+1, 0);

    for(int i=2; i*i<=MAX; i++) {
        //primes[i]에 소인수 있으면 이 숫자 포함한 배수들에도 다 동일한 소인수
        if(primes[i]!=0) {
            continue;
        }
        //소인수 없으면 이 숫자 배수들에 전부 소인수(=i) 넣기
        //이 숫자는 소수니까 소인수 넣지 않고 0 유지
        for(int j=i*i; j<=MAX; j+=i) {
            if (primes[j] == 0) {
                primes[j] = i;
            }
        }
    }
    return primes;
}

vector<int> getPrimeFactors(int k, vector<int> &primes) {
    //소인수 저장할 배열 선언
    vector<int> factors;
    //소수 아닐 때
    while(primes[k]!=0) {
        factors.push_back(primes[k]);
        k/=primes[k];
    }
    //마지막 소수는 안 들어간 상태이므로 반복문 끝나고 추가
    factors.push_back(k);
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    //소인수 배열 만들기
    vector<int> primes = getPrimes();

    for(int i=0; i<n; i++) {
        cin >> k;
        //k 소인수들 구하기
        vector<int> factors = getPrimeFactors(k, primes);

        for (int num : factors) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}