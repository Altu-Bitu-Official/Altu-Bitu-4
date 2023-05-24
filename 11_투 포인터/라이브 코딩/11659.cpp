#include <iostream>
#include <vector>

using namespace std;

/* 누적 합 계산하기 */
void calSum(int n, vector<int> &sum) {
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1]; // 첫번째 수부터 i번째 수까지의 누적 합
    }
}

/* i번째 수부터 j번째 수까지의 합 계산하기 */
int getPrefixSum(int i, int j, vector<int> &sum) {
    return sum[j] - sum[i - 1];
}

int main() {
    // 입출력 성능 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j;
    vector<int> sum;

    // 입력
    cin >> n >> m;
    sum.assign(n + 1, 0); // sum[0]을 0으로 설정 -> i-1이 0인 경우 따로 분리하지 않아도 됨
    for(int i = 1; i <= n; i++) {
        cin >> sum[i];
    }

    // 연산
    calSum(n, sum);

    while (m--) {
        cin >> i >> j;
        // 출력
        cout << getPrefixSum(i, j, sum) << "\n";
    }
    return 0;
}