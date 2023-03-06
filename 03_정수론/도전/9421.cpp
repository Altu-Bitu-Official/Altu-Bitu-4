#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
const int MAX=1000000;

void isPrime(vector<bool> &is_prime) {
    is_prime[0]=is_prime[1]=false;

    for(int i=2; i*i<MAX; i++) {
        if(is_prime[i]) {
            for(int j=i*i; j<MAX; j+=i) {
                is_prime[j]=false;
            }
        }
    }
}

vector<int> getPrimes(int n, vector<bool> &is_prime) {
    vector<int> primes;
    set<int> sums;
    int square_sum;
    string tmp;

    for(int i=2; i<n; i++) {
        //n보다 작은 소수 중에
        if(is_prime[i]) {
            tmp = to_string(i);

            //각 자리 제곱 합이 상근 수인 수 찾기
            while(true) {
                //제곱합 초기화
                square_sum=0;

                //각 자리 제곱합 변수에 저장
                for(int j=0; j<tmp.size(); j++) {
                    square_sum+=(tmp[j]-'0')*(tmp[j]-'0');
                }

                //제곱합 존재하면 루프 돌게되니까 break
                if(sums.find(square_sum)!=sums.end()) {
                    break;
                }

                //존재 안 하면 제곱합 배열에 추가
                sums.insert(square_sum);

                //제곱합 1 되면 상근수 배열에 추가 후 break
                if(square_sum==1) {
                    primes.push_back(i);
                    break;
                }

                //두 경우 다 아니면 제곱합 구할 수 갱신하고 다시 루프
                tmp = to_string(square_sum);
            }

            //제곱합 배열 초기화
            sums.clear();
        }
    }

    return primes;
}

int main() {
    int n;

    cin >> n;

    vector<bool> is_prime(MAX, true);
    isPrime(is_prime);

    vector<int> primes=getPrimes(n, is_prime);

    for (int num : primes) {
        cout << num << "\n";
    }

    return 0;
}