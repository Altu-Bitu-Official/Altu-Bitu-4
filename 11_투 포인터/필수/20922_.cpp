#include <iostream>
#include <vector>
#include <algorithm>

// 추가제출
// 내 코드랑 다른점:
//   - 나는 for문으로 right를 옮기려 했고, 여기서는 while문을 씀.
//     중간에 left 움직였다가 right 움직였다가 계속 왔다갔다 하기 때문에 for문 내 i라는 딱 하나의 인덱스를 고정하는건 비효율적임을 배움.
//   - 굳이 map 라이브러리 안 써도 count 벡터로 숫자 세기 가능.

using namespace std;
const int MAX_NUM = 100001; // 수열 내 숫자 최대값

int getMaxLen(vector<int> &number, int n, int k)
{
    vector<int> count(MAX_NUM, 0); // 수열 내 각 숫자의 개수 저장
    int left = 0, right = 0;       // 포인터 초기화
    int max_len = 0;               // 최대 수열 길이 초기화

    while (right < n) // right 포인터를 0에서부터 끝까지 계속 옮김
    {
        // 인덱스를 옮겨가면서 해당 숫자를 수열에 옮길 수 있을지 판단
        if (count[number[right]] >= k)
        {                          // 해당 숫자의 개수가 k가 넘으면 추가 불가
            count[number[left]]--; // left 숫자를 더이상 고려하지 않고
            left++;                // left 포인터를 옮김(아마 right까지 계속 가게 될것.)
        }
        else
        {                                         // right가 가르키는 숫자의 빈도가 k보다 작으면 추가할 수 있음
            count[number[right]]++;               // right 숫자를 세줌
            right++;                              // 전진
            max_len = max(max_len, right - left); // 최대 수열이라면, 길이 업데이트
        }
    }
    return max_len;
}
/**[백준 20922: 겹치는 건 싫어]
 * 1. 맨 왼쪽부터 투포인터를 이용해 탐색하며 left와 right 사이에 있는 숫자들의 개수를 count에 저장
 * 2. 오른쪽에 있는 숫자를 수열에 추가할 수 있으면 추가하고 right++
 * 3. 오른쪽에 있는 숫자를 수열에 추가할 수 없으면 현재 수열의 맨 왼쪽 숫자를 삭제하고 left 이동
 */
int main()
{
    int n, k;
    vector<int> numbers;

    // 입력
    cin >> n >> k;
    numbers.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    // 연산 & 출력
    cout << getMaxLen(numbers, n, k);
    return 0;
}