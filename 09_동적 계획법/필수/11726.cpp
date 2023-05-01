#include <iostream>
#include <vector>

using namespace std;

int get_recnum(int n) {
    vector<int> rec(n + 1, 0);
    rec[1] = 1;
    rec[2] = 2;

    // 1과 2로 구성되어 있다.
    for (int i = 3; i <= n; i++) {
        rec[i] = (rec[i - 1] + rec[i - 2]) % 10007;
    }

    return rec[n];
}
int main() {
    int n;
    cin >> n;

    cout << get_recnum(n) << endl;

    return 0;
}
