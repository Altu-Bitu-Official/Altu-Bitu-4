#include <iostream>
#include <vector>

using namespace std;

int isPrime(int n, int k, vector<bool> &is_prime) {
    //몇 번째로 지워진 건지 카운트
    int cnt = 0;
    is_prime[0] = is_prime[1] = false;

    //2부터 돌면서
    for(int i=2; i*i<=n; i++) {
        //소수면
        if(is_prime[i]) {
            //소수도 지워야하니까 자기 자신 포함한 소수의 배수 돌면서
            for(int j=i; j<=n; j+=i) {
                //소수의 배수가 true면
                if(is_prime[j]) {
                    //false 처리 후 cnt 1 증가
                    is_prime[j] = false;
                    cnt++;
                }
                //돌다가 cnt==k 되면 그 때 false 처리한 값 반환
                if(cnt==k) {
                    return j;
                }
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    //소수 여부 저장할 배열
    vector<bool> is_prime(n+1, true);

    cout << isPrime(n, k, is_prime);

    return 0;
}