#include "iostream"
#include "queue"
#include "cmath"

using namespace std;

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    priority_queue<int, vector<int>, greater<int> > numbers;    // 오름차순 우선순위 큐

    cin >> n;
    // numbers에 n번째까지의 입력을 push
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        numbers.push(tmp);
    }

    // n = n*n -n
    n = pow(n, 2) - n;
    // 들어오는 모든 입력에 대해 top보다 tmp가 클 경우, top을 pop하고 tmp를 push
    // 현재까지의 입력 중 상위 n개의 값만을 우선순위 큐에 가지고 있도록 함.
    while (n--) {
        cin >> tmp;
        if (tmp > numbers.top()) {
            numbers.pop();
            numbers.push(tmp);
        }
    }
    // n번째로 큰 수는 numbers의 가장 작은 원소 즉, top이므로 top을 출력
    cout << numbers.top();
}