#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;    //10의 9승
const int MAX_N = 11;   //최대 N의 크기
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3;   //expression에서 인덱스와 연산자의 연결 관계
const int EXP_NUM = 4;  //연산자 개수

int n;
int nums[MAX_N];    //입력받은 숫자를 저장하는 배열
int expression[EXP_NUM];    //연산자 별 개수를 저장하는 배열
int max_val = -INF, min_val = INF;  //식 결과의 최대, 최소

/**
 * 연산자를 하나씩, 총 (N-1)개가 될 때까지 뽑는다.
 *
 * cnt: 뽑은 연산자의 개수
 * curr_val: 현재 연산값
 */
//시행 횟수와 현재 값을 받아 연산자를 뽑고 현재 값을 갱신하거나, 종료 조건에 도달했을 시 최종 값이 최대, 최소값에 부합하는지 검사하는 함수.
void backtrack(int cnt, int curr_val) {
    // 재귀 호출 종료 조건: (N-1)개의 연산자를 다 뽑은 경우
    if (cnt == n - 1) {    //카운트가 n-1 == 연산자를 n-1번 뽑았을 떼
        max_val = max(max_val, curr_val);   //기존값과 비교해 최대값 구하기
        min_val = min(min_val, curr_val);   //기존값과 비교해 최소값 구하기
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
        int new_sum = 0;    //합을 저장하는 변수
        switch (i) {
            case ADD:   //i == 0
                new_sum = curr_val + nums[cnt + 1];     //현재 값에서 다음 숫자 덧셈.
                break;  
            case SUB:   //i == 1
                new_sum = curr_val - nums[cnt + 1];     //현재 값에서 다음 숫자 뺄셈.
                break;
            case MUL:   //i == 2
                new_sum = curr_val * nums[cnt + 1];     //현재 값에서 다음 숫자 곱셈.
                break;
            case DIV:   //i == 3
                new_sum = curr_val / nums[cnt + 1];     //현재 값에서 다음 숫자 나눗셈.
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
        cin >> nums[i];     //nums 배열에 주어진 숫자 입력받기
    }
    for (int i = 0; i < EXP_NUM; i++) {
        cin >> expression[i];   //연산자별 개수 입력받기
    }

    // 연산
    backtrack(0, nums[0]);

    // 출력
    cout << max_val << '\n' << min_val;
    
    return 0;
}