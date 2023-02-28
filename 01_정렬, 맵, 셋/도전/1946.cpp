#include <iostream>
#include <map>
#include <vector>

using namespace std;

void counter(int m, map<int, int> &apy) {
    int countNum = 1;
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
            countNum++;
            me = i;
        }
    }
    cout << countNum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--) {
        int m;
        cin >> m;
        map<int, int> apy;
        int document, interview;

        // 입력
        for (int j = 0; j < m; j++) {
            cin >> document >> interview;
            apy[document] = interview;
        }
        // 연산 및 출력
        counter(m, apy);
    }

    return 0;
}
