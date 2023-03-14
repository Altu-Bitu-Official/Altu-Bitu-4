#include <iostream>
#include <deque>

using namespace std;

int main() {
    // 입력
    int n, k;
    cin >> n >> k;

    deque<int> d;

    while (n--) {
        d.push_front(n + 1);
    }

    // 출력 및 연산
    cout << "<";
    while (true) {
        for (int i = 0; i < k - 1; i++) {
            // k-1 번 만큼 덱의 앞에서 빼서 뒤에 추가
            int num = d.front();
            d.pop_front();
            d.push_back(num);
        }
        // k번째에는 출력 후 덱에서 제거
        cout << d.front();
        d.pop_front();

        if (d.empty()) {
            cout << ">";
            break;
        }
         cout << ", ";
    }
}

