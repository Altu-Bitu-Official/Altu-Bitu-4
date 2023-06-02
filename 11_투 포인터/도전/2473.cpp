#include <iostream>
#include <vector>
#include <tuple>
#include <cmath> // abs()
#include <algorithm> // sort()

#define INF 3 * 1e9 + 1
typedef long long ll;
using namespace std;

/**투 포인로 세 용액의 합이 가장 0에 가까운 용액 튜플 리턴*/
tuple<int, int, int> calSum(vector<ll> liquid) {
    ll min_value = INF;
    tuple<int, int, int> ans;
    
    // 세 용액 중 하나(i)를 고정하고 나머지 두 용액에 해당될 용액 쌍을 투포인터로 탐색
    for (int i = 0; i < liquid.size() - 2; i++) {
        // 포인터 초기화
        int left = i + 1;               // 두 번째 용액
        int right = liquid.size() - 1;  // 세 번째 용액
        // left는 항상 right보다 작아야 함
        while (left < right) {
            ll value = liquid[i] + liquid[left] + liquid[right]; // 현재 세 용액의 합
            if (abs(value) < min_value) {
                min_value = abs(value);
                ans = {liquid[i], liquid[left], liquid[right]};
            }
            if (value < 0) { // 현재 값이 0보다 작으면 더 큰 값을 만들어야 함 -> left++
                left++;
            } else if (value > 0) { // 현재 값이 0보다 크다면 더 작은 값을 만들어야 함 -> right--
                right--;
            } else { // 현재 값이 0이면 이보다 더 0보다 가까운 값은 존재하지 않으므로 탐색 종료
                return ans;
            }
        }
    }
    return ans;
}
/**[백준 2473: 세 용액]
 * 1. 합이 가장 0에 가까운 세 용액의 인덱스를 각각 i, left, right로 설정
 * 2. i는 고정하고, left와 right로 투포인터를 이용해 탐색
 * 3. 현재 세 용액의 합이 0보다 작으면 left++
 * 4. 현재 세 용액의 합이 0보다 크면 right++
 * 5. 현재 세 용액의 합이 0이면 이보다 더 0에 가까운 값은 존재하지 않으므로 탐색 종료
*/
int main() {
    int n;
    vector<ll> liquid;
    
    // 입력
    cin >> n;
    liquid.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    // 연산
    sort(liquid.begin(), liquid.end());
    tuple<int, int, int> ans = calSum(liquid);

    // 출력
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
    return 0;
}