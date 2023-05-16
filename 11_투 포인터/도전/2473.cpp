#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> findLiquid(int n, vector<int>& values) {
    sort(values.begin(), values.end());  // 특성값 정렬

    int nearestSum = INT_MAX;  // 초기화
    vector<int> ans;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int mixtureSum = values[i] + values[left] + values[right];

            if (abs(mixtureSum) < abs(nearestSum)) { // 절대값비교
                nearestSum = mixtureSum;
                ans = { values[i], values[left], values[right] }; // 업데이트
            }

            if (mixtureSum == 0)
                return ans;
            else if (mixtureSum > 0)
                right--;
            else
                left++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;  // 전체 용액의 수

    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];  // 용액의 특성값 입력

    vector<int> result = findLiquid(n, values);

    // 출력
    for (int i = 0; i < 3; i++)
        cout << result[i] << " ";

    return 0;
}
