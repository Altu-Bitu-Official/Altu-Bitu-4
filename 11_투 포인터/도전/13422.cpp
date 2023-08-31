#include <iostream>
#include <vector>
using namespace std;

int steal(int n, int m, int k, vector<int>& money) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (i < m) {
            sum += money[i];
        }
    }
    if (n == m) {
        count = sum < k ? 1 : 0;
    }
    else {
        for (int j = 0; j < n; j++) {
            if (sum < k) {
                count++;
            }
            sum += money[(j + m) % n] - money[j];
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> money(n);
        for (int j = 0; j < n; j++)
            cin >> money[j];  // 각 집에서 보관 중인 돈의 양

        int result = steal(n, m, k, money);

        // 출력
        cout << result << endl;
    }

    return 0;
}
