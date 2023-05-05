#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int N;
vector<int> numbers;
vector<int> operators;
int min_result = numeric_limits<int>::max();
int max_result = numeric_limits<int>::min();

void dfs(int index, int result) {
    if (index == N) {
        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {
            operators[i]--;
            int next_result = result;
            switch (i) {
            case 0:
                next_result += numbers[index];
                break;
            case 1:
                next_result -= numbers[index];
                break;
            case 2:
                next_result *= numbers[index];
                break;
            case 3:
                next_result /= numbers[index];
                break;
            }
            dfs(index + 1, next_result);
            operators[i]++;
        }
    }
}

int main() {
    cin >> N;
    numbers.resize(N);
    operators.resize(4);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    dfs(1, numbers[0]);

    cout << max_result << endl;
    cout << min_result << endl;

    return 0;
}
