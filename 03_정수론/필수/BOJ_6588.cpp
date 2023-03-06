#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;//문제에서 제시한 n의 최댓값 1000000을 벡터의 크기로 설정

vector<int> getPrime() {
    vector<int> primeset(MAX + 1, 1);//소수집합 생성, 1로 초기화
    //1이면 소수, 0이면 소수가 아님
    primeset[0] = 0; primeset[1] = 0;
    for (int i = 2; i*i <= MAX; i++) {//이 반복문 구조 잘 기억하기.i=2부터 시작, i부터 루트i까지.
        if (primeset[i] == 1) {
            for (int j = i*i; j <= MAX; j+=i) {//j는 i의 제곱부터 시작, 한 시행마다 j에 i를 더해주어야 한다.

                primeset[j] = 0;//소수의 배수들을 지운다.(0으로 만든다)

            }
        }

    }
    return primeset;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1;
    int flag;
    vector<int> primes = getPrime();

    while (n != 0) {
        cin >> n;
        for (int k = 3; k <= n;k+=2) {//문제에서 구하려는 것에 2는 포함되지 않으므로 3부터 시작, 홀수여야 하므로 k+=2.
            if (primes[k] == 1) {
                if (primes[n - k] == 1) {
                    flag = 1;
                    cout << n << " = " << k << " + " << n - k << "\n";
                    break;//for문 밖으로.

                }
                else {//n에서 소수를 뺐는데 그게 소수가 아닌 홀수라면
                    flag = 0;
                    continue;//다음 k에 대해 계속 진행
                }
            }
            else {//소수인 k가 나올때까지 진행
                flag = 0;
                continue;
            }
            if (flag == 0) {
                cout << "Goldbach's conjecture is wrong.\n";
            }
        }

    }

    return 0;
}