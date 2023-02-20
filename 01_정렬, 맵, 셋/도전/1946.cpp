#include <iostream>
#include <map>

using namespace std;

int count(int m, map<int, int> &apy) {
    int count = 1;
    // 시간 초과
    /*for (int i = 1; i <= m; i++) {
        for (int j = 1; j < i; j++) {
            if (apy[i] > apy[j]) {
                count++;
                break;
            }
        }
    }*/
    int me = 1;

    for (int i = 2; i <= m; i++) {
        if (apy[i] < apy[me]) {
            count++;
            me = i;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];

    // 입력 및 연산
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        map<int, int> apy;
        int document, interview;

        for (int j = 0; j < m; j++) {
            cin >> document >> interview;
            apy[document] = interview;
        }
        arr[i] = count(m, apy);
    }

    // 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}
