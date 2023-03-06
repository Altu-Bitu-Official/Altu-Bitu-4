#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct Input {
    int change;
    char stop;
};

vector<char> getWheelOfFortune(queue<Input> inputs, int n) {
    vector<char> result(n, NULL);
    Input input;
    int sum;

    while (!inputs.empty()) {
        input = inputs.front();
        inputs.pop();

        sum += input.change;
        if (result[sum % n] == NULL) {
            result[sum % n] = input.stop;
        } else if (result[sum % n] == input.stop) {
            continue;
        } else {
            result.resize(1);
            result[0] = '!';
            return result;
        }
    }
    return result;
}


int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // n: 돌림판 칸 수, k: 돌리는 횟수
    Input input; // 임시로 input값을 받을 변수
    queue<Input> inputs;

    // 입력
    cin >> n >> k;
    while (k--) {
        cin >> input.change >> input.stop;
        inputs.push(input);
    }

    vector<char> result = getWheelOfFortune(inputs, n);

    for (int i = 0; i < result.size(); i++) {
        cout << (result[i] = (result[i] == NULL) ? '?' : result[i]);
    }

}
