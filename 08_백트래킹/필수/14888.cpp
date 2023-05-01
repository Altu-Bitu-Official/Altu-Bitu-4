#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX_N = 11;
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3;
const int EXP_NUM = 4;

int n;
int nums[MAX_N];
int expression[EXP_NUM];
int max_val = -INF, min_val = INF;

/**
 * 연산자를 하나씩, 총 (N-1)개가 될 때까지 뽑는다.
 *
 * cnt: 뽑은 연산자의 개수
 * curr_val: 현재 연산값
 */
void backtrack(int cnt, int curr_val) {
    // 재귀 호출 종료 조건: (N-1)개의 연산자를 다 뽑은 경우
    if (cnt == n - 1) {
        max_val = max(max_val, curr_val);
        min_val = min(min_val, curr_val);
        return;
    }
    
    // i: 연산자 번호
    for (int i = 0; i < EXP_NUM; i++) {
        // 사용할 연산자가 남아있지 않으면, 사용 불가
        if (expression[i] == 0) {
            continue;
        }
        
        // 연산자 사용
        expression[i]--;
        int new_sum = 0;
        switch (i) {
            case ADD:
                new_sum = curr_val + nums[cnt + 1];
                break;
            case SUB:
                new_sum = curr_val - nums[cnt + 1];
                break;
            case MUL:
                new_sum = curr_val * nums[cnt + 1];
                break;
            case DIV:
                new_sum = curr_val / nums[cnt + 1];
                break;
        }
        
        // 다음 연산자 선택
        backtrack(cnt + 1, new_sum);
        
        // 연산자 반납
        expression[i]++;
    }
}

/**
 * 모든 연산자 조합을 시도해보면서 최대값과 최솟값을 찾는다.
 * 모든 연산자 조합을 만들기 위해 가장 왼쪽에 들어갈 연산자부터 하나씩 선택한다.
 */
int main() {
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < EXP_NUM; i++) {
        cin >> expression[i];
    }

    // 연산
    backtrack(0, nums[0]);

    // 출력
    cout << max_val << '\n' << min_val;
    
    return 0;
}