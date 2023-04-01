#include "iostream"
#include "queue"

using namespace std;

void Mission(int charge, priority_queue<int> &presents) {
    int tmp;
    // 선물을 충전하는 경우에는 선물 전달하지 않음
    if (charge != 0) {
        while (charge--) {
            cin >> tmp;
            presents.push(tmp);
        }
        return;
    }

    // 선물할 선물이 없다면 -1 출력, 아니라면 top을 출력
    if (presents.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << presents.top() << '\n';
        presents.pop();
    }
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, charge;
    priority_queue<int> presents;

    //입력
    cin >> n;

    while (n--) {
        cin >> charge;
        Mission(charge, presents);
    }
}
