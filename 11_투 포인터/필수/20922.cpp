#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_NUM = 100001; //수열 내 숫자 최대값

/**같은 정수를 k개 이하로 포함하는 최장 연속 부분 수열 길이 구하기*/
int getMaxLen(vector<int> &number, int n, int k) {
    vector<int> count(MAX_NUM, 0); // 수열 내 각 숫자의 개수 저장
    int left = 0, right = 0; // 포인터 초기화
    int max_len = 0; // 최대 수열 길이 초기화
    
    while (right < n) {
        // right를 오른쪽으로 옮겨가면서 right번째 숫자를 수열에 추가할 수 있을 지 판단
        if (count[number[right]] >= k) { // right에 있는 숫자의 개수가 k가 넘으면 -> 추가 불가
            count[number[left]]--;  // left 숫자 삭제
            left++;
        } else { // right에 있는 숫자의 개수가 k보다 작으면 -> 추가 가능
            count[number[right]]++; // right 숫자 추가
            right++;
            max_len = max(max_len, right - left); // 최대 수열 길이 갱신
        }
    }
    return max_len;
}
/**[백준 20922: 겹치는 건 싫어]
 * 1. 맨 왼쪽부터 투포인터를 이용해 탐색하며 left와 right 사이에 있는 숫자들의 개수를 count에 저장
 * 2. 오른쪽에 있는 숫자를 수열에 추가할 수 있으면 추가하고 right++
 * 3. 오른쪽에 있는 숫자를 수열에 추가할 수 없으면 현재 수열의 맨 왼쪽 숫자를 삭제하고 left 이동
*/
int main() {
    int n, k;
    vector<int> numbers;
    
    //입력
    cin >> n >> k;
    numbers.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    //연산 & 출력
    cout << getMaxLen(numbers, n, k);
    return 0;
}