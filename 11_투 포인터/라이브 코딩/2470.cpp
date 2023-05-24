#include <iostream>
#include <vector>
#include <cmath> //abs()
#include <algorithm> //sort()

using namespace std;
typedef pair<int, int> ci;

/* 투 포인로 두 용액의 합이 가장 0에 가까운 용액 쌍 리턴 */
ci mixLiquid(vector<int> &liquid, int left, int right){
    int min_value = abs(liquid[left] + liquid[right]); // 두 용액의 합의 값 중 가장 가까운 값
    ci ans = {liquid[left], liquid[right]}; // 합이 가장 0에 가까운 두 용액의 특성값

    // left는 항상 right보다 작아야 함
    while (left < right) {
        int value = liquid[left] + liquid[right]; // 두 용액 혼합
        if(abs(value) < min_value) { // 현재 합이 min_value보다 더 0에 가까우면
            min_value = abs(value);  // min_value 갱신
            ans = {liquid[left], liquid[right]}; // ans 갱신
        }
        if (value < 0) { // 현재 값이 0보다 작다면 더 큰 값을 만들어야 함 -> lef++
            left++;
        } else if (value > 0) { // 현재 값이 0보다 크다면 더 작은 값을 만들어야 함 -> right--
            right--;
        } else { // 현재 값이 0이면 이보다 더 0보다 가까운 값은 존재하지 않으므로 탐색 종료
            break;
        }
    }
    return ans;
}

int main() {
    int n;
    vector<int> liquid;

    // 입력
    cin >> n;
    liquid.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    // 연산
    sort(liquid.begin(), liquid.end());
    ci ans = mixLiquid(liquid, 0, n - 1);

    // 출력
    cout << ans.first << " " << ans.second;
    return 0;
}