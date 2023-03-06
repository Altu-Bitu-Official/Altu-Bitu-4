#include "iostream"
#include "vector"

const int MAX = 1000000; // num의 최대범위
using namespace std;

// 에라토스테네스의 체
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

// 3부터 2씩 늘려가며 i와 num - i 둘다 소수라면 출력하기
void printGoldbachsConjecture(int num, vector<int> &primes) {
    for (int i = 3; i < primes.size(); i+=2) {
        if (primes[i] == 0 && primes[num - i] == 0) {
            cout << num << " = " << i << " + " << (num - i) << "\n";
            return;
        }
    }
    // 끝까지 돌았음에도 return하지 않았다면 틀렸다는 메세지 출력
    cout << "Goldbach's conjecture is wrong.";
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> primes = getPrimes(); // 1부터 1000000까지 소수 판별
    int num= -1;

    while (num != 0) {
        // 입력
        cin >> num;
        // 입력으로 0이 들어왔다면 종료
        if (num == 0)
        {
            return 0;
        }
        // 연산과 출력
        printGoldbachsConjecture(num, primes);
    }
}