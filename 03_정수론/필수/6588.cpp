#include <iostream>
#include <vector>

using namespace std;
const int MAX=1000000;

void isPrime(vector<bool> &is_prime) {
    is_prime[0]=is_prime[1]=false;

    for(int i=2; i*i<=MAX; i++) {
        //소수면
        if(is_prime[i]) {
            //소수의 배수들 처리
            for(int j=i*i; j<MAX; j+=i) {
                is_prime[j]=false;
            }
        }
    }
}

string getPrimesSum(vector<bool> &is_prime, int input) {
    //가장 작은 홀수 소수인 3부터 돌면서
    for(int i=3; i<MAX; i++) {
        //두 숫자 모두 소수 조건 만족 안 하면 i 1씩 증가시키면서 다시 검사
        if(is_prime[i] && is_prime[input-i]) {
            return to_string(input)+" = "+ to_string(i)+" + "+ to_string(input-i)+"\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    vector<bool> is_prime(MAX, true);
    isPrime(is_prime);

    while(true) {
        cin >> input;

        if(input==0) {
            break;
        }

        cout << getPrimesSum(is_prime, input);
    }

    return 0;
}