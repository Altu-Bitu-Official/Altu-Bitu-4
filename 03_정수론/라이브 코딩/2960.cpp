#include <iostream>
#include <vector>

using namespace std;

int findPrime(int n, int k) {
    vector<bool> is_prime(n + 1, true); //소수 여부 저장
    int cnt = 0; //현재 지워진 수의 개수 저장

    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) { //이미 지워진 수이면 탐색 X
            continue;
        }
        for (int j = i; j <= n; j += i) {
            if (!is_prime[j]) { //이미 지워진 수이면 탐색 X
                continue;
            }
            if ((++cnt) == k) {
                //지금 지워지는 수가 k번째 지워지는 수이면 현재 수 반환
                return j;
            }
            is_prime[j] = false; //현재 수 지우기
        }
    }
    return -1;
}
int main() {
    //입력
    int n, k, cnt = 0;
    cin >> n >> k;

    //출력
    cout << findPrime(n, k);

    return 0;
}