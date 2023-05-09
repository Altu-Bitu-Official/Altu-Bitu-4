#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int mid, int m, int n, vector<int>& snack) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += snack[i] / mid;
    }
    return cnt >= m;
}

int binarySearch(int n, int m, vector<int>& snack) {
    int left = 1;
    int right = snack[n - 1];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, m, n, snack)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    //입력
    int m, n;
    cin >> m;
    cin >> n;
    vector<int> snack(n);
    for (int i = 0; i < n; i++) {
        cin >> snack[i];
    }
    sort(snack.begin(), snack.end());


    cout << binarySearch(n, m, snack);
    return 0;
}
