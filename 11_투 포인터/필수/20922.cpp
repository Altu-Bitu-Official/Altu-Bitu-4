#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest(int N, int K, vector<int>& arr) {
    int left = 0, right = 0, maxLength = 0;
    unordered_map<int, int> count;

    // 투포인터
    while (right < N) {
        count[arr[right]]++; // 등장 횟수 세기

        while (count[arr[right]] > K) { // k 초과 시 왼쪽 포인터 이동
            count[arr[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1); // 길이 업데이트
        right++;
    }

    return maxLength;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N); // 수열 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << longest(N, K, arr) << '\n';

    return 0;
}
