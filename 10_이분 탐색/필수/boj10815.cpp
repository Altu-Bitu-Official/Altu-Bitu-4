#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key, vector<int>& s_card) {
    int left = 0;
    int right = n - 1;
    int mid;
    // 키 값의 존재여부 구하기
    while (left <= right) {
        mid = (left + right) / 2;
        if (s_card[mid] == key) {   // key 값이 배열의 중앙값과 같을 때
            return 1;
        }
        else if (s_card[mid] > key) { // key 값이 배열의 중앙값보다 작을 때-> 더 작은 값 탐색
            right = mid - 1;
        }
        else {  // key 값이 배열의 중앙값보다 클때-> 더 큰 값 탐색
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    int n, m;
    cin >> n;
    vector<int> s_card(n);
    for (int i = 0; i < n; i++) {
        cin >> s_card[i];
    }
    sort(s_card.begin(), s_card.end());

    cin >> m;
    int card;
    while (m--) {
        cin >> card;
        cout << binarySearch(n, card, s_card) << " ";
    }
    return 0;
}