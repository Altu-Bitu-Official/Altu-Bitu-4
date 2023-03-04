#include "iostream"
#include "string"
#include "vector"

using namespace std;

vector<int> getPrimes(int num) {
    vector<int> primes(num + 1, 0);
    for (int i = 2; i * i <= num; i++) {
        if (primes[i] != 0) { //소수가 아니면 탐색 X
            continue;
        }
        //j의 가장 작은 소인수는 i
        for (int j = i * i; j <= num; j += i) {
            if (primes[j] == 0) {
                primes[j] = i;
            }
        }
    }
    return primes;
}

void printGoldbachsConjecture(int num) {
    vector<int> primes = getPrimes(num);

    for (int i = 3; i < primes.size(); i++) {
        if (primes[i] == 0 && primes[num - i - 1]) {
            cout << num << " = " << i << " + " << (num - i) << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.";
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;

    while (true) {
        // 입력
        getline(cin, num);
        // 종료 입력이 들어온다면 return
        if (num == "0") {
            return 0;
        }
        // 연산과 출력
        printGoldbachsConjecture(stoi(num));
    }
}