#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> prime; // 소수를 담을 수 있는 벡터
bool check[1000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (long long i= 2; i <= 1000000; i++) {
        if (check[i])
            continue;
        prime.push_back(i);
        for (long long j= i * i; j <= 1000000; j += i) {
            check[j] = true;
        }
    }

    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int n2 = n / 2;
        for (int i = 0; i < n2; i++) {
            //n과 소수를 담고있는 벡터의 첫번째 요소부터 차이를 계산하면 나머지값 찾을 수 있음
            int diff = n - prime[i];
            if (!check[diff]) { //check[diff]를 통해 이 숫자가 소수인지 아닌지 판별
                cout << n << " = " << prime[i] << " + " << diff; //소수이면 출력
                break;
            }
        }
        cout << "\n";
    }
}